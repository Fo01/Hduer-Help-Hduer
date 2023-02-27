<?php                                                                           
switch ($_POST['gender']) {                                                     
   case 'male':                                                                 
   case 'female':                                                               
   case 'other':                                                                
                                                                                
      echo "<h1>Congratulations!<br/>                               
           You are: ".$_POST['gender']. ".</h1>";                                
   break;                                                                       
                                                                                
   default:                                                                     
                                                                                
      echo "<h1><span style=\"color:  red;\">WARNING:</span><br/>                         
           Invalid input value specified.</h1>";                      
   break;                                                                       
}                                                                               
?>
