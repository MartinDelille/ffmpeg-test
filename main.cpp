#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
#ifndef INT64_C
/// see http://code.google.com/p/ffmpegsource/issues/detail?id=11#c13
#define INT64_C(c) (c ## LL)
/// and http://code.google.com/p/ffmpegsource/issues/detail?id=11#c23
#define UINT64_C(c) (c ## ULL)
#endif

#include <libavformat/version.h>

#include <libavutil/imgutils.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

#ifdef __cplusplus
}
#endif
using namespace std;

class Pouet {
	string _name;

public:
	Pouet(string name) : _name(name) {
	}

	void mange() {
		cout << _name << " mange" << endl;
	}
};

int main(int argc,
         char *argv[]) {
    if (argc < 2) {
        cout << "No argument. Exiting!" << endl;
        return -1;
    }

    AVFormatContext *_formatContext;
    int error = avformat_open_input(&_formatContext, argv[1], nullptr, nullptr);
    Pouet p("Martin");
	p.mange();
}
