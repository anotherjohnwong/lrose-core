////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program PhaseDiff
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params path ] specify params file path\n"
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("PhaseDiff");
    tt->comment_text = tdrpStrDup("This program calculates the phase difference between two radar scans. It is used to evaluate scans for use in calibrating the refractivity algorithm.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters controlling debug outputs.");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("debug flag");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'verbose'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("verbose");
    tt->descr = tdrpStrDup("verbose debug flag");
    tt->help = tdrpStrDup("If true, verbose debug messages will be printed.");
    tt->val_offset = (char *) &verbose - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("PROCESS TRIGGERING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the process triggering.");
    tt++;
    
    // Parameter 'trigger_mode'
    // ctype is '_trigger_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("trigger_mode");
    tt->descr = tdrpStrDup("Input triggering mode");
    tt->help = tdrpStrDup("In TIME_LIST mode, the program operates on every input file between the start and end times specified on the command line.\n");
    tt->val_offset = (char *) &trigger_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("trigger_mode_t");
    tt->enum_def.nfields = 1;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TIME_LIST");
      tt->enum_def.fields[0].val = TIME_LIST;
    tt->single_val.e = TIME_LIST;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("PROCESS I/O PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the input and output locations.");
    tt++;
    
    // Parameter 'input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url");
    tt->descr = tdrpStrDup("Input URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/radar");
    tt++;
    
    // Parameter 'raw_iq_in_input'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("raw_iq_in_input");
    tt->descr = tdrpStrDup("Flag indicating whether the raw I and Q values are included in the input stream.");
    tt->help = tdrpStrDup("If true, the raw fields will be read from the input stream. If false, the raw fields will be calculated from the NIQ/AIQ values which must be inluded in the input stream instead.");
    tt->val_offset = (char *) &raw_iq_in_input - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'raw_i_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("raw_i_field_name");
    tt->descr = tdrpStrDup("Raw I field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to TRUE.");
    tt->val_offset = (char *) &raw_i_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("MeanI");
    tt++;
    
    // Parameter 'raw_q_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("raw_q_field_name");
    tt->descr = tdrpStrDup("Raw Q field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to TRUE.");
    tt->val_offset = (char *) &raw_q_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("MeanQ");
    tt++;
    
    // Parameter 'niq_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("niq_field_name");
    tt->descr = tdrpStrDup("NIQ field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &niq_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("NIQ");
    tt++;
    
    // Parameter 'input_niq_scale'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("input_niq_scale");
    tt->descr = tdrpStrDup("Input NIQ scale value");
    tt->help = tdrpStrDup("The NIQ value from the input source is multiplied by this value before the data is used. For most radars this value should be 0.1. For SPOL this value should be 0.025.");
    tt->val_offset = (char *) &input_niq_scale - &_start_;
    tt->single_val.d = 0.1;
    tt++;
    
    // Parameter 'invert_target_angle_sign'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("invert_target_angle_sign");
    tt->descr = tdrpStrDup("Flag indicating whether to invert the sign of the target angles.");
    tt->help = tdrpStrDup("This fix should be done upstream, but is added here just in case.\nUsed only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &invert_target_angle_sign - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'aiq_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("aiq_field_name");
    tt->descr = tdrpStrDup("AIQ field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &aiq_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("AIQ");
    tt++;
    
    // Parameter 'snr_in_input'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("snr_in_input");
    tt->descr = tdrpStrDup("Flag indicating whether the SNR field is included in the input stream.");
    tt->help = tdrpStrDup("If true, the SNR field will be read from the input stream. If false, the SNR field will be calculated from the power field which must be inluded in the input stream.\nThe SNR field is only needed if the raw I/Q values are not included in the input files and so must be calculated from the NIQ/AIQ values.");
    tt->val_offset = (char *) &snr_in_input - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'snr_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("snr_field_name");
    tt->descr = tdrpStrDup("Signal-to-noise ratio field name in the input stream.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &snr_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("SNR");
    tt++;
    
    // Parameter 'power_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("power_field_name");
    tt->descr = tdrpStrDup("Power field name in the input stream.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &power_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("DM");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::apps/refract/src/PhaseDiff/TiMREX/output");
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'lookback_secs'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("lookback_secs");
    tt->descr = tdrpStrDup("Lookback period in seconds");
    tt->help = tdrpStrDup("This is the length of time to look back to find the radar file to use for differencing. This should generally be set somewhere between 30 and 60 minutes.");
    tt->val_offset = (char *) &lookback_secs - &_start_;
    tt->single_val.l = 1800;
    tt++;
    
    // Parameter 'lookback_search_margin'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("lookback_search_margin");
    tt->descr = tdrpStrDup("Lookback search margin in seconds.");
    tt->help = tdrpStrDup("If there is no radar file within this number of seconds of the trigger file time minus lookback_secs, no output file will be produced.");
    tt->val_offset = (char *) &lookback_search_margin - &_start_;
    tt->single_val.l = 300;
    tt++;
    
    // Parameter 'elevation_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("elevation_num");
    tt->descr = tdrpStrDup("Index of the tilt we are processing in the radar volume");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &elevation_num - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("COLORSCALE PARAMETERS");
    tt->comment_text = tdrpStrDup("These colorscale files can be generated as a convenience to the user. They are not required for the calculating of the phase difference fields.");
    tt++;
    
    // Parameter 'create_phase_diff_colorscale'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("create_phase_diff_colorscale");
    tt->descr = tdrpStrDup("Flag indicating whether to create the phase diff colorscale file.");
    tt->help = tdrpStrDup("This creates a CIDD colorscale file that matches the colors used by Frederic Fabry in his original phase_diff program.");
    tt->val_offset = (char *) &create_phase_diff_colorscale - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'phase_diff_colorscale_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("phase_diff_colorscale_path");
    tt->descr = tdrpStrDup("Full path for the phase diff colorscale file.");
    tt->help = tdrpStrDup("Used only if create_phase_diff_colorscale is set to true.");
    tt->val_offset = (char *) &phase_diff_colorscale_path - &_start_;
    tt->single_val.s = tdrpStrDup("colorscales/phase_diff.colors");
    tt++;
    
    // Parameter 'create_niq_colorscale'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("create_niq_colorscale");
    tt->descr = tdrpStrDup("Flag indicating whether to create the NIQ colorscale file.");
    tt->help = tdrpStrDup("This creates a CIDD colorscale file that matches the colors used by Frederic Fabry in his original phase_diff program.");
    tt->val_offset = (char *) &create_niq_colorscale - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'niq_colorscale_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("niq_colorscale_path");
    tt->descr = tdrpStrDup("Full path for the NIQ colorscale file.");
    tt->help = tdrpStrDup("Used only if create_niq_colorscale is set to true.");
    tt->val_offset = (char *) &niq_colorscale_path - &_start_;
    tt->single_val.s = tdrpStrDup("colorscales/niq.colors");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
