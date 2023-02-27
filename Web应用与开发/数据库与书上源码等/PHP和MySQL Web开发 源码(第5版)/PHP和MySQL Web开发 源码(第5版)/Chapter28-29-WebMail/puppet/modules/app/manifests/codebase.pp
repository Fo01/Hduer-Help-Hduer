class app::codebase {

  info("Deploying Codebase for environment $environment")

  file { "/vagrant/public/.htaccess" :
     group => "www-data",
     owner => "root",
     mode => 775,
     source => "puppet:///modules/app/config/$::environment/public/.htaccess"
  }
  
  composer::exec { 'update-codebase' :
    cmd => "update",
    cwd => "/vagrant",
    logoutput => true
  }
}
