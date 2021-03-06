/*******************************************
 * ridds2mom_tdrp.h
 *
 * TDRP header file for 'ridds2mom' module.
 *
 * Code for program ridds2mom
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _ridds2mom_tdrp_h
#define _ridds2mom_tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

typedef enum {
  DEBUG_OFF = 0,
  DEBUG_NORM = 1,
  DEBUG_VERBOSE = 2
} ridds2mom_debug;

typedef enum {
  NEXRAD_FORMAT = 0,
  CONSTANT_FORMAT = 1
} ridds2mom_input_stream_format;

typedef enum {
  IN_TAPE = 0,
  IN_UDP = 1,
  IN_SHMEM = 2
} ridds2mom_input_device;

typedef enum {
  LL_FORMAT = 0,
  DS_FORMAT = 1,
  RIDDS_FORMAT = 2
} ridds2mom_output_format;

typedef enum {
  OUT_UDP = 0,
  OUT_SHMEM = 1,
  OUT_FMQ = 2
} ridds2mom_output_device;

typedef struct {
  double latitude;
  double longitude;
  double altitude;
} ridds2mom_ZR;

/*
 * typedef for main struct - ridds2mom_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug *****/

  ridds2mom_debug debug;

  /***** instance *****/

  char* instance;

  /***** malloc_debug_level *****/

  int malloc_debug_level;

  /***** input_stream_format *****/

  ridds2mom_input_stream_format input_stream_format;

  /***** input_device *****/

  ridds2mom_input_device input_device;

  /***** input_tape_name *****/

  char* input_tape_name;

  /***** input_tape_wait *****/

  int input_tape_wait;

  /***** short_tape *****/

  tdrp_bool_t short_tape;

  /***** input_udp_port *****/

  int input_udp_port;

  /***** input_shmem_key *****/

  int input_shmem_key;

  /***** output_format *****/

  ridds2mom_output_format output_format;

  /***** output_device *****/

  ridds2mom_output_device output_device;

  /***** write_fmq_output *****/

  tdrp_bool_t write_fmq_output;

  /***** write_udp_output *****/

  tdrp_bool_t write_udp_output;

  /***** write_shmem_output *****/

  tdrp_bool_t write_shmem_output;

  /***** output_udp_port *****/

  int output_udp_port;

  /***** output_udp_address *****/

  char* output_udp_address;

  /***** output_shmem_key *****/

  int output_shmem_key;

  /***** output_fmq_url *****/

  char* output_fmq_url;

  /***** output_fmq_size *****/

  int output_fmq_size;

  /***** output_fmq_nslots *****/

  int output_fmq_nslots;

  /***** output_fmq_compress *****/

  tdrp_bool_t output_fmq_compress;

  /***** output_ds_dbz *****/

  tdrp_bool_t output_ds_dbz;

  /***** output_ds_vel *****/

  tdrp_bool_t output_ds_vel;

  /***** output_ds_spw *****/

  tdrp_bool_t output_ds_spw;

  /***** output_ds_snr *****/

  tdrp_bool_t output_ds_snr;

  /***** vol_coverage_path *****/

  char* vol_coverage_path;

  /***** radar_id *****/

  int radar_id;

  /***** radar_name *****/

  char* radar_name;

  /***** site_name *****/

  char* site_name;

  /***** radar_location *****/

  ridds2mom_ZR radar_location;

  /***** time_correction *****/

  int time_correction;

  /***** use_wallclock_time *****/

  tdrp_bool_t use_wallclock_time;

  /***** samples_per_beam *****/

  int samples_per_beam;

  /***** polarization_code *****/

  int polarization_code;

  /***** beam_width *****/

  double beam_width;

  /***** wavelength *****/

  double wavelength;

  /***** avg_xmit_pwr *****/

  double avg_xmit_pwr;

  /***** peak_xmit_pwr *****/

  double peak_xmit_pwr;

  /***** receiver_mds *****/

  double receiver_mds;

  /***** noise_dbz_at_100km *****/

  double noise_dbz_at_100km;

  /***** receiver_gain *****/

  double receiver_gain;

  /***** antenna_gain *****/

  double antenna_gain;

  /***** system_gain *****/

  double system_gain;

  /***** print_summary *****/

  tdrp_bool_t print_summary;

  /***** summary_interval *****/

  int summary_interval;

  /***** print_header *****/

  tdrp_bool_t print_header;

  /***** header_interval *****/

  int header_interval;

  /***** write_archive_fmq *****/

  tdrp_bool_t write_archive_fmq;

  /***** archive_fmq_url *****/

  char* archive_fmq_url;

  /***** archive_fmq_size *****/

  int archive_fmq_size;

  /***** archive_fmq_nslots *****/

  int archive_fmq_nslots;

  /***** archive_fmq_compress *****/

  tdrp_bool_t archive_fmq_compress;

  /***** print_max_min_byte *****/

  tdrp_bool_t print_max_min_byte;

} ridds2mom_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * ridds2mom_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   ridds2mom_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int ridds2mom_tdrp_load_from_args(int argc, char **argv,
                                ridds2mom_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * ridds2mom_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than ridds2mom_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   ridds2mom_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int ridds2mom_tdrp_load(char *param_file_path,
                      ridds2mom_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * ridds2mom_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See ridds2mom_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int ridds2mom_tdrp_load_defaults(ridds2mom_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * ridds2mom_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void ridds2mom_tdrp_sync(void);

/*************************************************************
 * ridds2mom_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

extern void ridds2mom_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * ridds2mom_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void ridds2mom_tdrp_free_all(void);

/*************************************************************
 * ridds2mom_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int ridds2mom_tdrp_check_all_set(FILE *out);

/*************************************************************
 * ridds2mom_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int ridds2mom_tdrp_check_is_set(char *param_name);

/*************************************************************
 * ridds2mom_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int ridds2mom_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * ridds2mom_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int ridds2mom_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * ridds2mom_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *ridds2mom_tdrp_table(void);

/*************************************************************
 * ridds2mom_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *ridds2mom_tdrp_init(ridds2mom_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

