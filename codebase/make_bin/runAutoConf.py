#!/usr/bin/env python

#===========================================================================
#
# Run autoconf etc on a dir
#
#===========================================================================

import os
import sys
import subprocess
from optparse import OptionParser
from datetime import datetime

def main():

    global options
    global subdirList
    global makefileCreateList

    global thisScriptName
    thisScriptName = os.path.basename(__file__)

    # We will be executing some sibling scripts. Get our path so that
    # the sibling scripts from the same path can be executed explicitly.
    global thisScriptDir
    thisScriptDir = os.path.abspath(os.path.dirname(__file__))

    # parse the command line

    usage = "usage: %prog [options]"
    homeDir = os.environ['HOME']
    parser = OptionParser(usage)
    parser.add_option('--debug',
                      dest='debug', default='False',
                      action="store_true",
                      help='Set debugging on')
    parser.add_option('--verbose',
                      dest='verbose', default='False',
                      action="store_true",
                      help='Set verbose debugging on')
    parser.add_option('--dir',
                      dest='dir', default=".",
                      help='Directory containing configure script')
    parser.add_option('--shared',
                      dest='shared', default='False',
                      action="store_true",
                      help='Create shared lib objects')

    (options, args) = parser.parse_args()

    if (options.verbose == True):
        options.debug = True
    
    if (options.debug == True):
        print >>sys.stderr, "Running %s:" % thisScriptName
        print >>sys.stderr, "  Dir:", options.dir

    # go to the dir

    os.chdir(options.dir)

    # run autoconffix the configure

    runAutoConf()
            
    sys.exit(0)

########################################################################
# run autoconf commands

def runAutoConf():

    if (options.shared == True):
        cmd = "libtoolize"
        runCommand(cmd)

    cmd = "aclocal"
    runCommand(cmd)

    cmd = "autoheader"
    runCommand(cmd)

    cmd = "automake --add-missing"
    runCommand(cmd)

    cmd = "autoconf"
    runCommand(cmd)

    #cmd = "autoreconf"
    #runCommand(cmd)

    cmd = os.path.join(thisScriptDir, "fixConfigure.py") + \
          " --dir %s" % options.dir
    runCommand(cmd)

########################################################################
# Run a command in a shell, wait for it to complete

def runCommand(cmd):

    if (options.debug == True):
        print >>sys.stderr, "running cmd:", cmd, " ....."
    
    try:
        retcode = subprocess.check_call(cmd, shell=True)
        if retcode != 0:
            print >>sys.stderr, "Child exited with code: ", retcode
            sys.exit(1)
        else:
            if (options.verbose == True):
                print >>sys.stderr, "Child returned code: ", retcode
    except OSError, e:
        print >>sys.stderr, "Execution failed:", e
        sys.exit(1)

    if (options.debug == True):
        print >>sys.stderr, ".... done"
    
########################################################################
# Run - entry point

if __name__ == "__main__":
   main()
