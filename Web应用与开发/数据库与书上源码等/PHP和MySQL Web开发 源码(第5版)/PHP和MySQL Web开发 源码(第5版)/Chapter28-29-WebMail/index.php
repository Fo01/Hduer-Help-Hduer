<?php
use GuzzleHttp\Client;
require_once __DIR__ . '/../vendor/autoload.php';

$settings = include_once 'settings.php';

$authParams = [
    'client_id' => $settings['client_id'],
    'client_secret' => $settings['client_secret'],
    'response_type' => 'code',
    'redirect_uri' => $settings['redirect_uri'],
    'scope' => implode(' ', $settings['scopes'])
];

$loginUrl = 'https://api.instagram.com/oauth/authorize?' . http_build_query($authParams);

?>
<html>
    <head>
        <title>PMWD - Chapter 30 - Instagram Demo</title>
        <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
        <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
        <script src="//maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS" crossorigin="anonymous"></script>
    </head>
    <body>
        <div class="container">
            <h1>PMWD - Chapter 30 (Instagram Demo)</h1>
            <div class="row">
                <div class="col-md-4 col-md-offset-4">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            <h3 class="panel-title">Login with Instagram</h3>
                        </div>
                        <div class="panel-body">
                            <a href="<?=$loginUrl?>" class="btn btn-block btn-primary">Login with Instagram</a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>