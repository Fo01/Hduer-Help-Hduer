<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Support\Facades\Auth;

class Authenticate
{
    public function handle($request, Closure $next, $guard = null)
    {
        
        if(!\Session::has('credentials')) {
            if($request->ajax()) {
                return response('Unauthorized.', 401);
            }
            
            return redirect()->guest('auth/login');
        }
        
        return $next($request);
    }
}
