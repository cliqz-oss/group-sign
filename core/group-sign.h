#pragma once
#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

enum ReturnCodes {
  GS_RETURN_FAILURE,
  GS_RETURN_SUCCESS,
  GS_SEED_TOO_SMALL,
  GS_NOT_SEEDED,
  GS_INVALID_GROUP_PRIVATE_KEY,
  GS_INVALID_GROUP_PUBLIC_KEY,
  GS_OUTPUT_BUFFER_TOO_SMALL,
  GS_INVALID_USER_PRIVATE_KEY,
  GS_INVALID_JOIN_RESPONSE,
  GS_INVALID_USER_CREDENTIALS,
  GS_NOT_SET_GROUP_PRIVATE_KEY,
  GS_NOT_SET_GROUP_PUBLIC_KEY,
  GS_NOT_SET_USER_CREDENTIALS,
  GS_INVALID_JOIN_MESSAGE,
  GS_INVALID_SIGNATURE
};

void GS_initState(void* state);
int GS_seed(void* state, char* seed, int seed_length);
int GS_setupGroup(void* state);
int GS_loadGroupPrivKey(void* state, char* data, int len);
int GS_loadGroupPubKey(void* state, char* data, int len);
int GS_startJoin(
  void* state,
  char* challenge, // in
  int challenge_len, // in
  char* gsk, int* len_gsk, // out
  char* joinmsg, int* len // out
);
int GS_finishJoin(
  char* publickey, int len_publickey, // in
  char* gsk, int len_gsk, // in
  char* joinresponse, int len, // in
  char* credentials, int* len_credentials // out
);
int GS_loadUserCredentials(void* state, char* in, int in_len);
int GS_exportGroupPrivKey(void* state, char* out, int* out_len);
int GS_exportGroupPubKey(void* state, char* out, int* out_len);
int GS_exportUserCredentials(void* state, char* out, int* out_len);
int GS_processJoin(void* state, char* joinmsg, int joinmsg_len, char* challenge, int challenge_len, char* out, int* out_len);
int GS_sign(void* state, char* msg, int msg_len, char* bsn, int bsn_len, char* signature, int* len);
int GS_verify(void* state, char* msg, int msg_len, char* bsn, int bsn_len, char* signature, int len);
int GS_getSignatureTag(char* signature, int sig_len, char* tag, int* tag_len);
size_t GS_getStateSize();
const char* GS_version();
const char* GS_curve();
int GS_success();
int GS_failure();
const char* GS_error(int error_code);

#ifdef __cplusplus
} // end extern "C"
#endif
