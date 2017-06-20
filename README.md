EthernetBonjour
===============

Fork of Bonjour (ZeroConf) Library for Arduino & Teensyduino from TrippyLightning

mDNS (registering services) and DNS-SD (service discovery) has been tested and works on:
Particle.io Photon boards

Testing together with open HomeKit accessories:

      EthernetBonjour.addServiceRecord("particle._hap",
                                   80,
                                   MDNSServiceTCP,
                                   "\x4sf=1\x14id=3C:33:1B:21:B3:00\x6pv=1.0\x04\c#=1\x04s#=1\x4\ff=0\x04sf=1\x0Bmd=particle");


