<?php

/*
|--------------------------------------------------------------------------
| Routes File
|--------------------------------------------------------------------------
|
| Here is where you will register all of the routes in an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.
|
*/

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| This route group applies the "web" middleware group to every route
| it contains. The "web" middleware group is defined in your HTTP
| kernel and includes session state, CSRF protection, and more.
|
*/

Route::group(['middleware' => ['web']], function() {
    Route::get('auth/login', [
        'as' => 'login',
        'uses' => 'Auth\AuthController@getLogin'
    ]);
    
    Route::get('auth/logout', 'Auth\AuthController@getLogout');
    Route::post('auth/login', 'Auth\AuthController@postLoginGMail');
});

Route::group(['middleware' => ['web', 'auth']], function () {
    
    Route::get('inbox', [
        'as' => 'inbox',
        'uses' => 'InboxController@getInbox'
    ]);
    
    Route::get('read/{id}', [
        'as' => 'read',
        'uses' => 'InboxController@getMessage'
    ])->where('id', '[0-9]+');
   
    Route::get('read/{id}/attachment/{partId}', [
        'as' => 'read.attachment',
        'uses' => 'InboxController@getAttachment'
    ])->where('partId', '[0-9]+(\.[0-9]+)*');
    
    Route::get('compose/{id?}', [
        'as' => 'compose',
        'uses' => 'InboxController@getCompose'
    ])->where('id', '[0-9]+');
    
    Route::get('inbox/delete/{id}', [
        'as' => 'delete',
        'uses' => 'InboxController@getDelete'
    ])->where('id', '[0-9]+');
    
    Route::post('compose/send', [
        'as' => 'compose.send',
        'uses' => 'InboxController@postSend'
    ]);
    
});
