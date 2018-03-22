const char string[] PROGMEM = R"=====(
<html>
<title> SEND STRING</title>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Calibri, Helvetica, sans-serif; color:white; background:  #232428;}
    
form {border: 3px solid white; margin:0px 400px; background-color: white; border-radius: 10px;}
    
input[type=text]{
    width: 100%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
    border-radius: 5px;
}
    
.button{
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
        
    
@media screen and (max-width: 640px) {
    form {border: 3px solid white; margin:0px 20px; background-color: white; border-radius: 10px;}
}
</style>
</head>

<body>
<h1 align='center'>ESP 8266 Message</h1>
      <form action ='msg'>
          <div class='container'>
              <label style='color:black; text-align:left;'><b>Message</b></label><br>
              <input type='text' placeholder='Enter message'  name ='mensahe' required>
              <br><br>
              <label style='color:black'><b>Recipient</b></label><br>
              <input type='text' placeholder='Enter destination address' name='rec'required>
              <br><br>
              <input type='submit' class='button' value='Send'>
              <input type='button' style='background-color:#279130' onClick='/dashboard' class='button' value='Dashboard'>
          </div>
      </form>
      
    </body>
</html>
)=====";
  

