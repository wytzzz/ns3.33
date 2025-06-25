#pragma once
#include "gquiche/quic/platform/api/quic_socket_address.h"
#include "ns3/inet-socket-address.h"
namespace ns3 {
quic::QuicSocketAddress GetQuicSocketAddr(const InetSocketAddress &addr);
InetSocketAddress GetNs3SocketAddr(const quic::QuicSocketAddress &addr);
} // namespace ns3
