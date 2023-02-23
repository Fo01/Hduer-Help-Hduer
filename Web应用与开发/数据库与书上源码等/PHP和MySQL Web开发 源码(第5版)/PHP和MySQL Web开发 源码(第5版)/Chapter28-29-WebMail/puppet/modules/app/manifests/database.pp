class app::database {

  class { '::mysql::server' :
     root_password => 'password',
     databases => {
     	'avennu' => {
     		ensure => 'present',
     		charset => 'utf8'
     	}
     }
  }
   
}
