 //<>//

//Trevor Gould

import processing.serial.*;  

Serial myPort;//Create object from Serial class
String val;  //better to remove from globals, its faster
//To change movie, call a seperate bash script
//just edit bash script to play call the desired .mov file
//dont forget to make it executable 
String cmd = "/bin/bash /Users/goutrevor/video1.sh";//change path to script
String cmd1 = "/bin/bash /Users/goutrevor/video2.sh";

void setup(){
  String portName = Serial.list()[1]; //Find port for serial transfer
  myPort = new Serial(this, portName, 9600);  //Set Baud and port
  
}

void draw(){
  if ( myPort.available() > 0) {  // If data is available,
     val = myPort.readStringUntil('\n');     // read it and store it in val
  }
  
 if(val !=null){ 
   val = trim(val);//try this
   println(val); //print it out in the console

   if(val.equals("c")){  
      runExternalCommand(cmd);//run video bash script
      delay(22000);//set delay to size of video plus extra; 1 second = 1000
      runExternalCommand(cmd1);
      delay(17000);
   }/*else if(val.equals("d")){
      runExternalCommand(cmd);//run video bash script
      delay(12000);
      runExternalCommand(cmd1);
   }*/
   else {
     
   }
  }
}
//This script runs the exec function to run a bash script
void runExternalCommand(String cmd) {

  String runCmd =  cmd;
  try {
    Runtime.getRuntime().exec(runCmd);
  }
  catch(IOException e) {
    println("runExternalCommand: IOException:" + e);
  }
}