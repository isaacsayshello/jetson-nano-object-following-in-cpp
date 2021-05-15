int usage()
{
	printf("usage: detectnet [--help] [--network=NETWORK] [--threshold=THRESHOLD] ...\n");
	printf("                 input_URI [output_URI]\n\n");
	printf("Locate objects in a video/image stream using an object detection DNN.\n");
	printf("See below for additional arguments that may not be shown above.\n\n");
	printf("positional arguments:\n");
	printf("    input_URI       resource URI of input stream  (see videoSource below)\n");
	printf("    output_URI      resource URI of output stream (see videoOutput below)\n\n");

	printf("%s", detectNet::Usage());
	printf("%s", videoSource::Usage());
	printf("%s", videoOutput::Usage());
	printf("%s", Log::Usage());

	return 0;
}


bool signal_recieved = false;

void sig_handler(int signo)
{
	if( signo == SIGINT )
	{
		LogVerbose("received SIGINT\n");
		signal_recieved = true;
	}
}
