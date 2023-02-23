<?php

namespace App\Providers;

use Illuminate\Support\ServiceProvider;
use App\Library\Imap\GmailConnection;

class ImapServiceProvider extends ServiceProvider
{
    /**
     * Bootstrap the application services.
     *
     * @return void
     */
    public function boot()
    {
        //
    }

    /**
     * Register the application services.
     *
     * @return void
     */
    public function register()
    {
        $this->app->singleton('Imap\Connection\GMail', function($app) {
            return new GmailConnection(config('imap.gmail.options'), config('imap.gmail.retries'), config('imap.gmail.params'));
        });
    }
}
