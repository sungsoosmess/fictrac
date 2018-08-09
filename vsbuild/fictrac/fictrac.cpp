/// FicTrac http://rjdmoore.net/fictrac/
/// \file       fictrac.cpp
/// \brief      FicTrac program.
/// \author     Richard Moore
/// \copyright  CC BY-NC-SA 3.0

#include "Logger.h"
#include "Trackball.h"
#include "timing.h"

#include <string>

using std::string;


int main(int argc, char *argv[])
{
    PRINT("///");
    PRINT("/// FicTrac:\tA webcam-based method for generating fictive paths.\n///");
    PRINT("/// Usage:\tfictrac CONFIG_FN [-v LOG_VERBOSITY]\n///");
    PRINT("/// \tCONFIG_FN\tPath to input config file (defaults to config.txt).");
    PRINT("/// \tLOG_VERBOSITY\t[Optional] One of DBG, INF, WRN, ERR.");
    PRINT("///");
    PRINT("/// Build date: %s", __DATE__);
    PRINT("///\n");

	//BOOST_LOG_TRIVIAL(fatal) << "\n####################################################################\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# FicTrac: A webcam-based method for generating fictive paths.     #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# Version: public release (build %s)                      #\n", __DATE__;
	//BOOST_LOG_TRIVIAL(fatal) << "# Copyright (C) 2011-2018 Richard Moore (rjdmoore@uqconnect.edu.au)#\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "####################################################################\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# This software uses libraries from the following projects:        #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#     - OpenCV (http://opencv.org)                                 #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#     - NLopt (http://ab-initio.mit.edu/nlopt/)                    #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# These libraries are not distributed with this release but are    #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# freely available as open-source projects.                        #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# This work is licensed under the Creative Commons                 #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# Attribution-NonCommercial-ShareAlike 3.0 Unported License.       #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# To view a copy of this license, visit                            #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# http://creativecommons.org/licenses/by-nc-sa/3.0/                #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY        #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE       #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR          #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR    #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE   #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "# USE OR OTHER DEALINGS IN THE SOFTWARE.                           #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "#                                                                  #\n";
	//BOOST_LOG_TRIVIAL(fatal) << "####################################################################\n\n\n";


	/// Parse args.
	string log_level = "info";
	string config_fn = "config.txt";
	for (int i = 1; i < argc; ++i) {
		if ((string(argv[i]) == "--verbosity") || (string(argv[i]) == "-v")) {
			if (++i < argc) {
				log_level = argv[i];
			}
			else {
                LOG_ERR("-v/--verbosity requires one argument (debug < info (default) < warn < error)!");
				return -1;
			}
		}
		else {
            config_fn = argv[i];
		}
	}

    /// Set logging level.
    Logger::setVerbosity(log_level);

	//// Catch cntl-c
	//signal(SIGINT, TERMINATE);

	//// Set high priority (when run as SU)
	//Utils::SET_PROCESS_PRIORITY(-15);

    Trackball tracker(config_fn);

    PRINT("\n\nPress any key to exit..");
    std::getchar();
}

