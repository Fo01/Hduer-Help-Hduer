<?php

namespace App\Http\Controllers\Auth;

use App\User;
use Validator;
use App\Http\Controllers\Controller;
use Illuminate\Foundation\Auth\ThrottlesLogins;
use Illuminate\Foundation\Auth\AuthenticatesAndRegistersUsers;
use Illuminate\Foundation\Auth\AuthenticatesUsers;
use Illuminate\Http\Request;
use App\Library\Imap\ImapException;

class AuthController extends Controller
{
    use AuthenticatesUsers;

    public function __construct()
    {
        $this->middleware('guest', ['except' => 'logout']);
    }

    public function postLoginGMail(Request $request)
    {
        $connection = \App::make('Imap\Connection\GMail');
        
        $connection->setUsername($request->get('email'))
                   ->setPassword($request->get('password'));
        
        try {
            $client = $connection->connect();
        } catch(ImapException $e) {
            return $this->sendFailedLoginResponse($request);
        }
        
        $credentials = [
            'user' => $request->get('email'),
            'password' => $request->get('password')
        ];
        
        \Session::put('credentials', $credentials);
        
        return redirect('inbox');
    }
}
