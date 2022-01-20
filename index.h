const char MAIN_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Car diagnostc</title>
    <style>
        *
        {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        
        }
/* /////////////////////////////////////////////// */
.switch {
  position: relative;
  display: inline-block;
  width: 90px;
  height: 34px;
}

.switch input {display:none;}
.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ca2222;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2ab934;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(55px);
  -ms-transform: translateX(55px);
  transform: translateX(55px);
}

/*------ ADDED CSS ---------*/
.on
{
  display: none;
}

.on, .off
{
  color: white;
  position: absolute;
  transform: translate(-50%,-50%);
  top: 50%;
  left: 50%;
  font-size: 10px;
  font-family: Verdana, sans-serif;
}

input:checked+ .slider .on
{display: block;}

input:checked + .slider .off
{display: none;}

/*--------- END --------*/

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;}
</style>
</head>
<body style="background-color: rgb(12, 1, 51); margin-left: 10%; margin-right: 10%;">
          
             <h1 style="color: rgb(255, 255, 255); text-align: center;">
                 DASHBOARD
             </h1>
             <center>
                <div style="width: auto; height: auto; background-color: rgb(255, 255, 255); border-radius: 10px; padding: 5%;">
                  // COMMAND DES LUMIERES
                    <h1 style="color: rgb(12, 1, 51);">COMMANDE LUMIERE</h1>
                     <h2 style="color: rgb(12, 1, 51);">LAMPE 1</h2>
                    <label class="switch">
                        <input type="checkbox" id="togBtn" name="lampe1" onclick="togle(this)">
                        <div class="slider round">
                         <!--ADDED HTML -->
                         <span class="on">ON</span>
                         <span class="off">OFF</span>
                         <!--END-->
                        </div>
                       </label>
                       <h2 style="color: rgb(12, 1, 51);">LAMPE 2</h2>
                    <label class="switch">
                        <input type="checkbox" id="togBtn" name="lampe2" onclick="togle(this)">
                        <div class="slider round">
                         <!--ADDED HTML -->
                         <span class="on">ON</span>
                         <span class="off">OFF</span>
                         <!--END-->
                        </div>
                       </label>
                       <h2 style="color: rgb(12, 1, 51);">LAMPE 3</h2>
                    <label class="switch">
                        <input type="checkbox" id="togBtn" name="lampe3" onclick="togle(this)">
                        <div class="slider round">
                         <!--ADDED HTML -->
                         <span class="on">ON</span>
                         <span class="off">OFF</span>
                         <!--END-->
                        </div>
                       </label>
                      //  COMMANDE DES PRISES
                       <h1 style="color: rgb(12, 1, 51);">COMMANDE PRISE</h1>
                     <h2 style="color: rgb(12, 1, 51);">PRISE 1</h2>
                    <label class="switch">
                        <input type="checkbox" id="togBtn" name="prise1" onclick="togle(this)">
                        <div class="slider round">
                         <!--ADDED HTML -->
                         <span class="on">ON</span>
                         <span class="off">OFF</span>
                         <!--END-->
                        </div>
                       </label>  
                 </div>
                  <h6 style="color: white;">KADILAB</h6>
             </center>
             

<script>

         function togle(state)
         {
            var dvPassport = document.getElementById("state");//recuperation de l'element cliker
            var xhttp = new XMLHttpRequest();  // variable de la requette xhttp
            
            if(state.checked) //verifi si le l'interupteur est sur on ou of
            { 
              //requette  d'allumage
              xhttp.open("GET",state.name, true); //Handle readADC server on ESP8266
              xhttp.send();
            }
            else
            {
               //requette d'extinction
              xhttp.open("GET",state.name+"off", true); //Handle readADC server on ESP8266
               xhttp.send();
            }

//            alert(state.checked);
//            alert(state.name);

         }
</script>  

</body>
</html>
)=====";
