#ifndef __RVS_TYPES_H__
#define __RVS_TYPES_H__

typedef unsigned char      t_rvs_uint8;
typedef t_rvs_uint8      * t_rvs_uint8_ptr;
typedef unsigned int       t_rvs_uint32;
typedef t_rvs_uint32     * t_rvs_uint32_ptr;
typedef unsigned long long t_rvs_uint64;
typedef signed long long   t_rvs_int64;
typedef unsigned char      t_rvs_boolean;
typedef unsigned int       t_rvs_size_t;
#define RVS_FALSE 0
#define RVS_TRUE (!RVS_FALSE)
#define RVS_NULL ((void *)0)
typedef struct {t_rvs_uint32 T[2];} t_rvs_2_uint32;
typedef struct {t_rvs_uint32 T[4];} t_rvs_4_uint32;

/* These are the largest integers RVS can handle in calculations */
typedef t_rvs_uint64 t_rvs_ulong;
typedef t_rvs_int64  t_rvs_slong;

/* This can be anything up to and including 64 bits */
typedef unsigned long long int t_rvs_test_id;

#endif
