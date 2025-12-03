# include "utils.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = write_bits_to_char;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Pid : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
