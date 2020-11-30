/**
 * @file Logging.hpp
 * @author paul
 * @date 01.05.19
 * @brief Declaration of the Logging class
 */

#ifndef SECRETBUNDESTAGSERVER_LOGGING_HPP
#define SECRETBUNDESTAGSERVER_LOGGING_HPP

#include <ostream>
#include <vector>

namespace util {

    /**
     * This class wraps around any output-stream and provides filtering and formatting for outputs.
     */
    class Logging {
        public:
            /**
             * CTor: pass an output-stream (by reference) and the logging level.
             * @see README for more information on logging-levels and verbosity
             * @param ostream some output-stream, for exmaple std::cout or a file
             * @param loggingLevel the level of verbosity between 0 (no information) and 4 (maximum), values larger 4 are the same as 4.
             */
            Logging(std::ostream &ostream, unsigned int loggingLevel);

            /**
             * Construct a copy of the log which will always print a certain prefix in front of the message
             * @param log the log which to use
             * @param prefix the prefix to print
             */
            Logging(const Logging &log, const std::string& prefix);

            /**
             * Print an error message (verbosity level 1, color red)
             * @param msg the string to print
             */
            void error(const std::string &msg);

            /**
             * Print an error message (verbosity level 2, color yellow)
             * @param msg the string to print
             */
            void warn(const std::string &msg);

            /**
             * Print an error message (verbosity level 3, color blue)
             * @param msg the string to print
             */
            void info(const std::string &msg);

            /**
             * Print an error message (verbosity level 4, color white)
             * @param msg the string to print
             */
            void debug(const std::string &msg);

            /**
             * Prints dank memes independent of verbosity
             * @param msg your bullshit content
             */
            void shitTalk(const std::string &msg);
        private:
            /**
             * Actual implementation of the logging, checks the verbosity level,
             * prepends a timestamp, changes the color (and resets it afterwards)
             * and prints the message with a newline.
             * @param string the string to print
             * @param level the verbosity
             * @param colorFormat a format string according to the ansi standard (see: https://en.wikipedia.org/wiki/ANSI_escape_code)
             * @see CTor and README.
             */
            void logImpl(const std::string &string, unsigned int level, const std::string &colorFormat);

            std::ostream &ostream;
            unsigned int loggingLevel;
            std::vector<std::string> prefixes;
    };
}

#endif //SECRETBUNDESTAGSERVER_LOGGING_HPP
