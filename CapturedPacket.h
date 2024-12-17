#ifndef CAPTUREDPACKET_H
#define CAPTUREDPACKET_H

// En pcapworker.h o en un header aparte

#include <vector>
#include <cstdint>
#include <QString>
#include <QDateTime>


typedef struct ip_header { //nombre
    u_char ver_ihl;        // Versi�n (4 bits) + Longitud de cabecera (4 bits)
    u_char tos;            // Tipo de servicio
    u_short tlen;          // Longitud total
    u_short identification; // Identificaci�n
    u_short flags_fo;      // Banderas (3 bits) + Desplazamiento de fragmento (13 bits)
    u_char ttl;            // Tiempo de vida (TTL)
    u_char proto;          // Protocolo
    u_short crc;           // Suma de verificaci�n del encabezado
    u_int op_pad;          // Opciones + Padding

    struct { //struct anonima pero con instancias de saddr y daddr que sirven para saber la direccion de origen y destino
        u_char byte1;
        u_char byte2;
        u_char byte3;
        u_char byte4;
    } saddr, daddr;        // Direcci�n IP origen y destino - variables de ip_header


} ip_header; //su-nombre que se utiliza para renombrar cada dato que requiera de esta estructura

typedef struct tcp_header {
    u_short sport;         // Puerto origen
    u_short dport;         // Puerto destino
    u_int seqnum;          // N�mero de secuencia
    u_int acknum;          // N�mero de acuse de recibo
    u_char data_offset;    // Desplazamiento de datos (4 bits), reservado (4 bits)
    u_char flags;          // Banderas de control
    u_short win;           // Tama�o de ventana
    u_short crc;           // Suma de verificaci�n
    u_short urgptr;        // Puntero urgente
} tcp_header;

typedef struct udp_header {
    u_short sport;         // Puerto origen
    u_short dport;         // Puerto destino
    u_short len;           // Longitud del datagrama UDP
    u_short crc;           // Suma de verificaci�n
} udp_header;



enum class TransportProtocol {
    TCP,
    UDP,
    OTRO
};

// Estructura para almacenar la información de un paquete capturado
struct CapturedPacket {
    int packetNumber;
    QDateTime timestamp;
    ip_header ip;
    TransportProtocol protocol;
    tcp_header tcp; // Válido si protocol == TCP
    udp_header udp; // Válido si protocol == UDP
    std::vector<uint8_t> rawData; // Datos crudos del paquete
};

#endif // CAPTUREDPACKET_H
