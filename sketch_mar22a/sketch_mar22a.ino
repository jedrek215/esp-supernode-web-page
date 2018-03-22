#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>
#include "string.h"

extern "C" {
#include <user_interface.h>
}

unsigned int request_i = 0;
unsigned int response_i = 0;
unsigned int ssid = ESP.getChipId();

String rootmessage = string;

String manageRequest(String request);

String str, rec, decodedrec, decodedmsg;
ESP8266WebServer server(80); //Server on port 80
/* Create the mesh node object */
ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ssid, manageRequest);

/**
 * Callback for when other nodes send you data
 *
 * @request The string received from another node in the mesh
 * @returns The string to send back to the other node
 */
void handleString(){
  server.send(200,"text/html",rootmessage);

  str = server.arg("mensahe");
  rec = server.arg("rec");
  
  decodedmsg = str;
  decodedmsg.replace("+"," ");
  Serial.println(decodedmsg);

  decodedrec = rec;
  decodedrec.replace("+"," ");
  Serial.println(decodedrec);
}
String manageRequest(String request)
{
  /* Print out received message */
  Serial.print("received: ");
  Serial.println(request);

  /* return a string to send back */
  char response[60];
  sprintf(response, "---------------Acknowledged %d",ESP.getChipId());
  return response;
}

void setup()
{
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.println("Setting up mesh node...");

  mesh_node.begin();

  server.on("/msg",handleString);
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
    
    mesh_node.acceptRequest();
    server.handleClient();
    if(decodedmsg.length()>0)
    {
      char request[60];
      sprintf(request, "%s from Mesh_Node%d.", decodedmsg.c_str(), ESP.getChipId());
      mesh_node.attemptScan(decodedmsg);
      decodedmsg = "";
    }
  }



