#pragma once
#include "absl/strings/string_view.h"
#include "gquiche/quic/core/quic_session.h"
#include "ns3-transport-stream.h"
#include <string>
namespace quic {
class Ns3QuicSessionBase : public QuicSession {
public:
  Ns3QuicSessionBase(
      QuicConnection *connection, QuicSession::Visitor *owner,
      const QuicConfig &config,
      const ParsedQuicVersionVector &supported_versions,
      QuicStreamCount num_expected_unidirectional_static_streams);
  Ns3QuicSessionBase(const Ns3QuicSessionBase &) = delete;
  Ns3QuicSessionBase &operator=(const Ns3QuicSessionBase &) = delete;
  ~Ns3QuicSessionBase() override {}
  using QuicSession::CanOpenNextOutgoingBidirectionalStream;
  using QuicSession::CanOpenNextOutgoingUnidirectionalStream;
  virtual Ns3TransportStream *OpenOutgoingBidirectionalStream() {
    return nullptr;
  }
  virtual Ns3TransportStream *OpenOutgoingUnidirectionalStream() {
    return nullptr;
  }
};
} // namespace quic
