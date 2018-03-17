const char login[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<title>Login</title>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Calibri, Helvetica, sans-serif; color:white; background:  #02112b;}

form {border: 3px solid white; margin:0px 500px; background-color: white; border-radius: 10px;}


input[type=text], input[type=password] {
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
}

button {
    background-color: #296ee5;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
}

.container {
    padding: 16px;
}

span.psw {
    float: right;
    padding-top: 16px;
}


@media screen and (max-width: 640px) {
    span.psw {
       display: block;
        float: none;}
    form {border: 3px solid white; margin:0px 20px; background-color: white; border-radius: 10px;}
}
</style>
</head>
<body>

<h2 align = "center">Real Mesh Control Management System</h2>

<form name = "loginform" action="/dashboard" method="post" onSubmit="return validateForm();" id="form1">
  <div class="container">
    <label for="uname" style="color:black"><b>Username</b></label>
    <input type="text" placeholder="Enter Username" name="usr" required>

    <label for="psw" style="color:black"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="psw" required>
        
    <button type="submit">Login</button>
  </div>
</form>
        
<script>
    function validateForm() {
        var un = document.loginform.usr.value;
        var pw = document.loginform.psw.value;
        var username = "admin"; 
        var password = "admin";
        if ((un == username) && (pw == password)) {
            return true;
        }
        else {
            alert ("Login was unsuccessful, please check your username and password");
            return false;
        }
  }
</script> 
    
</body>
</html>
)=====";
