<?php

return [
    'client_id' => 'da2f8e3cdcef481e9114d7ab9bc8d466',
    'client_secret' => 'ac9eae18b8ba43ceb12aabb0870c3620',
    'redirect_uri' => 'http://' . $_SERVER['HTTP_HOST'] . '/complete-oauth.php',
    'scopes' => [
        'likes',
        'basic',
        'public_content'
    ]
];