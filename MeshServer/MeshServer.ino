#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>
#include "string.h"

extern "C" {
#include <user_interface.h>
}

//delete when done
struct station_info *stat_info;
struct ip_addr *IPaddress;
IPAddress address;

unsigned int request_i = 0;
unsigned int response_i = 0;
unsigned int ssid = ESP.getChipId();

String rootmessage = string;

String manageRequest(String request);

String str, rec, decodedrec, decodedmsg;
ESP8266WebServer server(80); //Server on port 80
/* Create the mesh node object */
ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(1, manageRequest);

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
	sprintf(response, "Hello world response #%d from Mesh_Node%d.", response_i++, ESP.getChipId());
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
  
  
  if(str.length()<5 && wifi_softap_get_station_num()>=1)
  {
    mesh_node.acceptRequest();
    Serial.println("Looping for client");
    server.handleClient();
    delay(500);
  stat_info = wifi_softap_get_station_info();
    while (stat_info != NULL)
  {
    IPaddress = &stat_info->ip;
    address = IPaddress->addr;
    Serial.print("\t");
    Serial.print(address);
    Serial.print("\r\n");
    stat_info = STAILQ_NEXT(stat_info, next);
  } 
    
  }
  
  else
  { WiFi.disconnect();
    mesh_node.acceptRequest();
    Serial.println("Waiting");
  /* Scan for other nodes and send them a message */
  char request[60];
  sprintf(request, "%s %s from Mesh_Node%d.", decodedrec.c_str(), decodedmsg.c_str(), ESP.getChipId());
  mesh_node.attemptScan(request);
  str = "";
  }

	
}
