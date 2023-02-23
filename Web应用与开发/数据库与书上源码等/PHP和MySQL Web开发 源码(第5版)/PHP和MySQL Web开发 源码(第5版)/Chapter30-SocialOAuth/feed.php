<?php

require_once __DIR__ . '/../vendor/autoload.php';

use GuzzleHttp\Client;

if(!isset($_SESSION['access_token']) || empty($_SESSION['access_token'])) {
    header("Location: index.php");
    exit;
}

$requestUri = "https://api.instagram.com/v1/users/self/media/recent";
$recentPhotos = [];
$tag = '';

if(isset($_GET['tagQuery']) && !empty($_GET['tagQuery'])) {
    $tag = urlencode($_GET['tagQuery']);
    $requestUri = "https://api.instagram.com/v1/tags/$tag/media/recent";
}

$client = new Client();

$response = $client->get($requestUri, [
    'query' => [
        'access_token' => $_SESSION['access_token']['access_token'],
        'count' => 50
    ]
]);

$results = json_decode($response->getBody(), true);

if(is_array($results)) {
    $recentPhotos = array_chunk($results['data'], 4);    
}


?>
<html>
    <head>
        <title>PMWD - Chapter 30 - Instagram Demo</title>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS" crossorigin="anonymous"></script>
        <script src="//code.jquery.com/jquery-1.12.0.min.js"></script>
        
        <script>
			$(document).ready(function() {
				$('.like-button').on('click', function(e) {
					e.preventDefault();

					var media_id = $(e.target).data('media-id');
				
					$.get('like.php?media_id=' + media_id, function(data) {
						if(data.success) {
							$(e.target).remove();
						}
					});
				});
			});
        </script>
    </head>
    <body>
        <div class="container">
            <h1>Instagram Recent Photos</h1>
            <div class="row">
                <div class="col-md-12">
                    <form class="form-horizontal" method="GET" action="feed.php">
                        <fieldset class="form-group">
                            <div class="col-xs-9 input-group">
                                <input type="text" class="form-control" id="tagQuery" name="tagQuery" placeholder="Search for a tag...." value="<?=$tag?>"/>
                                <span class="input-group-btn">
                                    <button type="submit" class="btn btn-primary"><i class="glyphicon glyphicon-search"></i> Search</button>
                                </span>
                            </div>
                        </fieldset>
                    </form>
                </div>
            </div>
            <div class="row">
                <?php foreach($recentPhotos as $photoRow): ?>
                    <div class="row">
                        <?php foreach($photoRow as $photo): ?>
                        <div class="col-md-3">
                            <div class="card">
                                <div class="card-block">
                                    <h4 class="card-title"><?=substr($photo['caption']['text'], 0, 30)?></h4>
                                    <h6 class="card-subtitle text-muted"><?=substr($photo['caption']['text'], 30, 30)?></h6>
                                </div>
                                <img class="card-img-top" src="<?=$photo['images']['thumbnail']['url']?>" alt="<?=$photo['caption']['text']?>">
                                <div class="card-block">
                                    <?php foreach($photo['tags'] as $tag): ?>
                                        <a href="#" class="card-link">#<?=$tag?></a>
                                    <?php endforeach?>
                                </div>
                                <div class="card-footer text-right">
                                    <?php if(!$photo['user_has_liked']): ?>
                                        <a data-media-id="<?=$photo['id']?>" href="#" class="btn btn-xs btn-primary like-button"><i class="glyphicon glyphicon-thumbs-up"></i> Like</a>
                                    <?php endif; ?>
                                </div>
                            </div>
                        </div>
                        <?php endforeach; ?>
                    </div>
                <?php endforeach; ?>
            </div>
        </div>
    </body>
</html>