<html>
<head>
    @section('stylesheets')
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">
    @show
</head>
<body>
    <div class="container">
    
    @if (count($errors) > 0)
        <div class="alert alert-danger">
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif
    
    @if(Session::has('success'))
    <div class="alert alert-success" role="alert">{{ Session::get('success') }}</div>
    @endif
    
    @if(Session::has('error'))
    <div class="alert alert-danger" role="alert">{{ Session::get('error') }}</div>
    @endif
    
    @if(Session::has('warning'))
    <div class="alert alert-warning" role="alert">{{ Session::get('warning') }}</div>
    @endif
    
    @if(Session::has('info'))
    <div class="alert alert-info" role="alert">{{ Session::get('info') }}</div>
    @endif
    
    @yield('main')
    </div>
</body>
    @section('javascript')
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS" crossorigin="anonymous"></script>
    @show
</html>
