#include <stdio.h>
#include <pcap.h>

void usage()
{
	printf("syntax error\n");
	printf("syntax : tcp-block <interface> <pattern>\n");
	printf("sample : tcp-block wlan0 \"Host: example.net\"\n");
}
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		usage();
		return -1;
	}
	char *dev = argv[1];
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t* h = pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
	if( h == nullptr)
	{
		printf("could not open device\n");
		return -1;
	}
	pcap_close(h);
	return 0;
}
