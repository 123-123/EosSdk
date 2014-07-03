// Copyright (c) 2013 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#ifndef EOS_MPLS_H
#define EOS_MPLS_H

#include <eos/base.h>

/**
 * MPLS related type definitions.
 */

namespace eos {

/// The action to take for an MPLS route.
enum mpls_action_t {
   MPLS_ACTION_NULL,
   MPLS_ACTION_PUSH,
   MPLS_ACTION_POP,
   MPLS_ACTION_SWAP,
};

/// Whether to use the pipe or uniform TTL inheritance mode.
enum mpls_ttl_mode_t {
   MPLS_TTLMODE_NULL,
   MPLS_TTLMODE_PIPE,     ///< "pipe" mode, don't inherit TTL from inner IP
   MPLS_TTLMODE_UNIFORM,  ///< "uniform" mode, inherit TTL from inner IP
};

/**
 * The inner payload type.
 * Used in a similar way to ethertype, as MPLS does not provide this
 * in the packet
 */
enum mpls_payload_type_t {
   MPLS_PAYLOAD_TYPE_NULL,
   MPLS_PAYLOAD_TYPE_MPLS,
   MPLS_PAYLOAD_TYPE_IPV4,
   MPLS_PAYLOAD_TYPE_IPV6,
   MPLS_PAYLOAD_TYPE_GUESS,
};

/**
 * An MPLS label, per RFC 3032.
 * Note: label id 0 (default value) is the explicit null label. LSRs
 * receiving this label are expected to pop it and perform ultimate IP
 * forwarding.
 * MPLS label numbers are 20 bits in size, covering the range 0..1048575.
 */
class EOS_SDK_PUBLIC mpls_label_t {
 public:
   mpls_label_t();
   explicit mpls_label_t(uint32_t label);

   uint32_t label() const;
   void label_is(uint32_t label);

   /**
    * Only the "default mpls label" returned by the default
    * constructor evaluates to false.
    */
   bool operator!() const;
   bool operator==(mpls_label_t const & other) const;
   bool operator!=(mpls_label_t const & other) const;
   bool operator<(mpls_label_t const & other) const;

   enum {
      MIN = 0,
      MAX = 0xFFFFF,  // 1048575
   };

 private:
   friend struct MplsLabelHelper;
   uint32_t label_;
};

/**
 * MPLS reserved label definitions (0..15).
 * See http://www.iana.org/assignments/mpls-label-values/mpls-label-values.xhtml
 */
static mpls_label_t const mpls_label_explicit_null_v4 = mpls_label_t(0);
static mpls_label_t const mpls_label_router_alert = mpls_label_t(1);
static mpls_label_t const mpls_label_explicit_null_v6 = mpls_label_t(2);
static mpls_label_t const mpls_label_implicit_null = mpls_label_t(3);
// 4..6 unassigned
static mpls_label_t const mpls_label_entropy_indicator = mpls_label_t(7);
// 8..12 unassigned
static mpls_label_t const mpls_label_gal = mpls_label_t(13);
static mpls_label_t const mpls_label_oam_alert = mpls_label_t(14);
// 15 unassigned

}  // end namespace eos

#include <eos/inline/mpls.h>

#endif // EOS_MPLS_H
