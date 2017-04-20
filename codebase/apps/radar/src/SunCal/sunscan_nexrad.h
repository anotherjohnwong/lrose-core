/****************************************************************
 * sunscan_nexrad.h
 *
 * C implementation of sunscan code, for use by NEXRAD
 *
 * Mike Dixon, EOL, NCAR
 * P.O.Box 3000, Boulder, CO, 80307-3000, USA
 *
 * April 2017
 *
 *****************************************************************/

#ifndef sunscan_nexrad_h
#define sunscan_nexrad_h

/* const variables */

#ifndef RAD_TO_DEG
#define RAD_TO_DEG 57.29577951308092
#endif
#ifndef DEG_TO_RAD
#define DEG_TO_RAD 0.01745329251994372
#endif

/* macros */

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

/* raw beam array, before interpolation
 * this is computed from the incoming pulses 
 */

#define NEXRAD_RAW_MAX_NAZ 1000
#define NEXRAD_RAW_MAX_NEL 1000

/* interpolated beams on regular grid */

#define nexradGridNAz 31
#define nexradGridNEl 21

/************************************************
 * structs for holding pulse and beam data
 */

/***************************************************************************
 * struct site_info: data for the observer's location.  The atmospheric 
 *                   parameters are used only by the refraction 
 *                   function called from function 'equ_to_hor'.
 *                   Additional parameters can be added to this 
 *                   structure if a more sophisticated refraction model 
 *                   is employed.
 *                    
 *  latitude         = geodetic latitude in degrees; north positive.
 *  longitude        = geodetic longitude in degrees; east positive.
 *  height           = height of the observer in meters.
 *  temperature      = temperature (degrees Celsius).
 *  pressure         = atmospheric pressure (millibars)
 */

typedef struct
{
  double latitude;
  double longitude;
  double height;
  double temperature;
  double pressure;
} nexrad_site_info;

/*****************************************************
 * Complex math object 
 */

typedef struct {
  double re;
  double im;
} nexrad_complex_t;

/******************************
 * Pulse implementation example
 */


typedef struct {
  
  /* meta data */
  
  int nGates; /* number of gates in use */
  double time; /* time in secs and fractions from 1 Jan 1970 */
  double prt; /* pulse repetition time (secs) */
  double el; /* elevation angle (deg) */
  double az; /* azimuth angle (deg) */
  
  /* IQ data */
  
  float *iq; /* nGates * 2 channels H and V */
  
} NexradPulse_t;

/*****************************
 * Beam implementation example
 *
 * Note that the meta-data  time, prt, el and az are not actually
 * used in this code, they are just included for context.
 */

typedef struct {
  
  /* meta data */
  
  /* int nexradNSamples; number of pulse samples in beam */
  int nGates; /* number of gates */
  double time; /* time for the center pulse of beam */
  double prt; /* pulse repetition time (secs) */
  double el; /* elevation angle for center of beam (deg) */
  double az; /* azimuth angle for center of beam(deg) */
  double elOffset; /* elevation offset to theoretical sun center (deg) */
  double azOffset; /* azimuth offset to theoretical sun center (deg) */
  
  /* Array of Pulses */
  
  // NexradPulse_t *pulses; /* pulses for this beam */
  
  /* moments */
  
  double powerH; /* power for H channel I*I+Q*Q */
  double powerV; /* power for V channel I*I+Q*Q */
  double dbmH;   /* power for H channel in dBm */
  double dbmV;   /* power for V channel in dBm */
  double dbm;    /* mean of dbmH and dbmV */
  double corrHV;  /* correlation between H and V */
  double phaseHV; /* mean phase between H and V */
  double dbBelowPeak; /* peak sun power minus mean dbm */
  double zdr; /* dbmH minus dbmV */
  double ratioDbmVH; /* ratio of V / H power */
  double SS; /* 1.0 / (zdr^2) */

  nexrad_complex_t rvvhh0;

} NexradBeam_t;

/*****************************************************
 * compute sun position using NOVA routines
 */

extern void rsts_SunNovasComputePosAtTime
  (nexrad_site_info here, double deltat,
   double *SunAz, double *SunEl, double distanceAU);

/*****************************************************
 * initialize the lat/lon/alt for which sun position
 * is computed lat/lon in degrees, alt_m in meters
 */

extern void nexradSetLocation(double lat, double lon, double alt_m);

/*****************************************************
 * initialize the pulse queue
 */

extern void nexradInitPulseQueue();
  
/*****************************************************
 * Check if beam is indexed to grid
 * returns 0 on success, -1 on failure
 */

extern int isBeamIndexedToGrid();

/*****************************************************
 * compute sun moments in dual-pol simultaneous mode
 * load up Beam with moments
 */

extern int computeMoments(int startGate,
                            int endGate,
                            NexradBeam_t *beam);

/*****************************************************
 * Add a beam to the raw beam array 
 */

extern int addBeam(NexradBeam_t *beam);

/*****************************************************
 * interp ppi moments onto regular 2-D grid
 *
 * global 2D array of Beam objects to store the interpolated data:
 * Beam _interpBeamArray[gridNAz][gridNEl];
 * double _interpDbmH[gridNAz][gridNEl];
 * double _interpDbmV[gridNAz][gridNEl];
 * double _interpDbm[gridNAz][gridNEl];
 */

extern void interpMomentsToRegularGrid();

/*****************************************************
 * compute receiver gain
 * based on solar flux from Penticton
 *
 * Reference: On Measuring WSR-88D Antenna Gain Using Solar Flux.
 *            Dale Sirmans, Bill Urell, ROC Engineering Branch
 *            2001/01/03.
 */
   
extern void computeReceiverGain();

#endif