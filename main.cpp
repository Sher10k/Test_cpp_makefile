#include <iostream>
#include <Eigen/Eigen>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <getopt.h>

#include "Source/videoParser.cpp"
#include "Header/myclass.h"

using namespace std;
using namespace Eigen;
using namespace cv;

struct Args
{
    std::string inlog       = "";
    std::string outlog      = "";
    bool debug         = false;

    bool parse(int argc, char *argv[])
    {
        // set some defaults
        const char *optstring = "i:o:dh";
        struct option long_opts[] = {
                { "input",         required_argument, 0, 'i' },
                { "output",      required_argument, 0, 'o' },
                { "debug",       no_argument,       0, 'd' },
                { "help",        no_argument,       0, 'h' },
                { 0, 0, 0 }
        };

        int c;
        while ((c = getopt_long (argc, argv, optstring, long_opts, 0)) >= 0) {
            switch (c) {
                case 'i': inlog       = std::string(optarg); break;
                case 'o': outlog      = std::string(optarg); break;
                case 'd': debug       = true;           break;
                case 'h': default: usage(); return false;
            };
        }

        if (inlog == "") {
            std::cerr << "Please specify logfile input" << std::endl;
            return false;
        }

        if (outlog  == "") {
            std::cerr << "Please specify video file output" << std::endl;
            return false;
        }

        return true;
    }

    void usage()
    {
        std::cout << "usage: log2vid [options]" << std::endl
                  << "" << std::endl
                  << "    Convert zcm log file to video file" << std::endl
                  << "" << std::endl
                  << "Example:" << std::endl
                  << "    log2vid -i zcm.log -o vid.avi " << std::endl
                  << "" << std::endl
                << "Options:" << std::endl
                << "" << std::endl
                << "  -h, --help              Shows this help text and exits" << std::endl
                << "  -i, --input=logfile     Input log to convert" << std::endl
                << "  -o, --output=videofile    Output video file" << std::endl
                << "  -d, --debug             Run a dry run to ensure proper converter setup" << std::endl
                << std::endl << std::endl;
    }
};

int main(int argc, char* argv[])
{
	Args args;
	if (!args.parse(argc, argv)) return 1;
	if (args.debug) return 0;
	
	VideoParser parser(args.inlog, args.outlog);
	parser.Run();



	cout << "Hello world!" << endl
	     << "123" << endl;
	Matrix4d M;
	M << 1, 0, 0, 0,
	     0, 1, 0, 0,
	     0, 0, 1, 0,
	     0, 0, 0, 1;
	cout << "M = " << endl << M << endl;

	int i = 42;
	cout << "i = " << i << endl;
	int *p = &i;
	int &r = i;
	int *&t = p;
	cout << "*p = i = " << *p << endl
	     << "p = &i = " << p << endl
	     << "&i = " << &i << endl
	     << "r = i = " << r << endl
	     << "&r = p = &i = " << &r << endl
	     << "t = " << t << endl
	     << "&t = " << &t << endl
	     << "*t = " << *t << endl
	     << "*&t = " << *&t << endl;
	*p = *p * *p;
	cout << "*p * *p = " << *p << endl << endl;

	int a = 3, b = 7;
	decltype(a) c = a;
	decltype((b)) d = a;
	decltype(a = b) f = b;
	cout << "++c = " << ++c << endl
	     << "++d = " << ++d << endl
	     << "f = " << f << endl;
	
//	string str = "12345 qwer";
	string str("12345 qwer");
	cout << "str: " << str << endl;


/*	string word;
	for (unsigned j = 0; cin >> word; j++ )
		cout << "\t" << j << "-" << word.length() << ": " << word << endl;	
*/	
	


	return 0;
}
