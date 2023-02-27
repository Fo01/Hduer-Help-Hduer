<?php

require_once __DIR__ . '/../vendor/autoload.php';

use GuzzleHttp\Client;

header("Content-Type: application/json");

if(!isset($_SESSION['access_token']) || empty($_SESSION['access_token'])) {
    header("Location: index.php");
    exit;
}

if(!isset($_GET['media_id']) || empty($_GET['media_id'])) {
    echo json_encode([
        'success' => false
    ]);
    return;
}

$media_id = $_GET['media_id'];

$requestUri = "https://api.instagram.com/v1/media/{$media_id}/likes";

$client = new Client();

$response = $client->post($requestUri, [
    'form_params' => [
        'access_token' => $_SESSION['access_token']['access_token']
    ]
]);

$results = json_decode($response->getBody(), true);

echo json_encode([
    'success' => true
]);