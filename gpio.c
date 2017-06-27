#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define CHIPPRO_GPIO_ROOT "/sys/class/gpio"
#define CHIPPRO_GPIO_EXPO "/sys/class/gpio/export"
#define CHIPPRO_GPIO_P_NO "132"
#define CHIPPRO_GPIO_P_D0 "/sys/class/gpio/gpio132"
#define CHIPPRO_GPIO_DIRE "/sys/class/gpio/gpio132/direction"
#define CHIPPRO_GPIO_VALU "/sys/class/gpio/gpio132/value"

int dir_exists(DIR* test_dir){
	
	if (test_dir) {
		closedir(test_dir);
		return 1;
	}
	
	fprintf( stderr, 
		"%s does not exist, or couldn't be accessed\n", 
		CHIPPRO_GPIO_ROOT);
	return 0;
}

int main(void){
	
	int rc = 0;
	printf("Begin GPIO control in C\n");
	
	// check for the gpio directory
	DIR* root_dir = opendir(CHIPPRO_GPIO_ROOT);
	if ( ! dir_exists(root_dir) ){
		return 1;
	}
	
	// see if the pin needs to be exported
	DIR* p_d0_dir = opendir(CHIPPRO_GPIO_P_D0);
	if ( dir_exists(p_d0_dir) == 0 ){
		// export the pin
		FILE *export_fp = NULL;
		export_fp = fopen(CHIPPRO_GPIO_EXPO, "w+");
		if(export_fp != NULL){
			fprintf( stderr, 
				"%s does not exist, or couldn't be accessed\n", 
				CHIPPRO_GPIO_EXPO);
			return 1;
		}
		
		
		rc += fprintf(export_fp, CHIPPRO_GPIO_P_NO);
		rc += fflush(export_fp);
		rc += fclose(export_fp);
		
		if(rc != 0){
			fprintf( stderr, 
				"%s does not exist, or couldn't be accessed\n", 
				CHIPPRO_GPIO_EXPO);
			return rc;
		}
	}
	
	// set the direction of the pin
	FILE *direction_fp = NULL;
	direction_fp = fopen(CHIPPRO_GPIO_DIRE, "w+");
	rc += fprintf(direction_fp, "out");
	rc += fflush(direction_fp);
	rc += fclose(direction_fp);
	
	if(rc != 0){
		fprintf( stderr, 
			"%s does not exist, or couldn't be accessed\n", 
			CHIPPRO_GPIO_DIRE);
		return rc;
	}
	
	char value[] = "0";
	while( 1 ){
		// set the value of the pin
		FILE *value_fp = NULL;
		value_fp = fopen(CHIPPRO_GPIO_VALU, "w+");
		rc += fprintf(value_fp, value);
		rc += fflush(value_fp);
		rc += fclose(value_fp);
		
		if(rc != 0){
			fprintf( stderr, 
				"%s does not exist, or couldn't be accessed\n", 
				CHIPPRO_GPIO_VALU);
			return rc;
		}
		
		if( strcmp(value, "0") )
			value[0] = '1';
		else
			value[0] = '0';
	}
	
	return 0;
}
