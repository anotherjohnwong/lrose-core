// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* RCS info
 *   $Author: dixon $
 *   $Locker:  $
 *   $Date: 2016/03/04 02:22:13 $
 *   $Id: ProfileSet.hh,v 1.2 2016/03/04 02:22:13 dixon Exp $
 *   $Revision: 1.2 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * ProfileSet: Class containing a set of vertical profiles for a given
 *             location.
 *
 * RAP, NCAR, Boulder CO
 *
 * May 2008
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef ProfileSet_HH
#define ProfileSet_HH

#include <string>
#include <vector>

#include "VertProfile.hh"

using namespace std;

class ProfileSet
{
 public:

  /*********************************************************************
   * Constructor
   */

  ProfileSet(const double lat, const double lon,
	     const bool debug_flag = false);
  

  /*********************************************************************
   * Destructor
   */

  virtual ~ProfileSet(void);
  

  ////////////////////
  // Access methods //
  ////////////////////

  /*********************************************************************
   * addProfile() - Add the given profile to the set.
   */

  void addProfile(const VertProfile &profile)
  {
    _profiles.push_back(profile);
  }
  

  /*********************************************************************
   * getLocation() - Get the location for the profiles.
   */

  void getLocation(double &lat, double &lon) const
  {
    lat = _lat;
    lon = _lon;
  }
  

  /*********************************************************************
   * getProfiles() - Get the profiles.
   */

  const vector< VertProfile > &getProfiles() const
  {
    return _profiles;
  }
  

 protected:

  bool _debug;
  
  double _lat;
  double _lon;
  
  vector< VertProfile > _profiles;
  
};


#endif
