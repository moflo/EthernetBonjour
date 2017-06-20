EthernetBonjourClass EthernetBonjour;



UDP udp;
TCPServer server = TCPServer(80);


void setup() {
  Particle.publish("EthernetBonjour Setup");

  String localIP = WiFi.localIP();
  Particle.publish("Announced from ", localIP );

  String remoteIP = udp.remoteIP();
  Particle.publish("UPD report from ", remoteIP );

  
  WiFi.connect();

  server.begin();
  
  EthernetBonjour.setUDP( &udp );
  
  EthernetBonjour.begin("particle");

  EthernetBonjour.addServiceRecord("particle._hap",
                                   80,
                                   MDNSServiceTCP,
                                   "\x4sf=1\x14id=3C:33:1B:21:B3:00\x6pv=1.0\x04\c#=1\x04s#=1\x4\ff=0\x04sf=1\x0Bmd=particle");

                                //   "\x4sf=1\x20id=3C:33:1B:21:B3:00\x6pv=1.0\x4c#=1\x4s#=1\x4ff=0\x4sf=1\x11md=particle");


}

void loop() {

  EthernetBonjour.run();
  
    TCPClient client = server.available();

  if (client){
    while (client.read() != -1);

    Particle.publish("EthernetBonjour Read Client");


    client.write("HTTP/1.1 200 Ok\n\n<html><body><h1>Ok!</h1></body></html>\n\n");
    client.flush();
    delay(5);
    client.stop();
  }

}

