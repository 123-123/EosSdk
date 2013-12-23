// Copyright (c) 2013 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#include <cassert>

#include "eos/decap_group.h"

namespace eos {

decap_group_mgr::decap_group_mgr() {
}

class decap_group_mgr_impl : public decap_group_mgr {
 public:
   decap_group_mgr_impl() {
   }
};

void
decap_group_mgr::decap_group_foreach(callback_func_decap_group handler,
                                     void *context) {
   // TODO: No op impl.
}

void
decap_group_mgr::decap_group_foreach(callback_func_decap_group handler,
                                     void * context,
                                     decap_group_t const &bookmark) {
   // TODO: No op impl.
}

void
decap_group_mgr::decap_group_set(decap_group_t const &group) {
   // TODO: No op impl.
}

void
decap_group_mgr::decap_group_del(std::string const & group_name) {
   // TODO: No op impl.
}

decap_group_mgr *
get_decap_group_mgr() {
   static decap_group_mgr_impl impl;
   return &impl;
}

};  // end namespace eos