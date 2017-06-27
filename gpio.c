#include <stdio.h>
#include <dirent.h>

#define CHIPPRO_GPIO_ROOT "/sys/class/gpio"
#define CHIPPRO_GPIO_EXPO "/sys/class/gpio/export"
#define CHIPPRO_GPIO_P_D0 "/sys/class/gpio/gpio132"
#define CHIPPRO_GPIO_DIRE "/sys/class/gpio/gpio132/direction"
#define CHIPPRO_GPIO_VALU "/sys/class/gpio/gpio132/value"

#define BUFFER_SIZE 128
char buffer[BUFFER_SIZE];

int dir_exists(DIR* test_dir){
	
	if (test_dir) {
		closedir(test_dir);
		return 1;
	}
	
	fprintf(
		stderr, 
		"%s does not exist, or couldn't be accessed\n", 
		CHIPPRO_GPIO_ROOT
	);
	return 0;
}

int main(void){
	
	printf("Begin GPIO control in C\n");
	
	DIR* root_dir = opendir(CHIPPRO_GPIO_ROOT);
	if ( dir_exists(root_dir) == 0 ){
		return 1;
	}
	
	// set buffer to 
	memset(buffer, 0, BUFFER_SIZE);
	strcat(buffer, CHIPPRO_GPIO_ROOT);
	strcat(buffer, CHIPPRO_GPIO_ROOT);
	
	DIR* pin_dir = opendir(CHIPPRO_GPIO_P_D0);
	if ( dir_exists(pin_dir) == 0 ){
		// pin needs to be exported
		
		FILE *export_fp = fopen()
		
	}
	
	
	
	
	return 0;
}
