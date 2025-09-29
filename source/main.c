#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

static u32 *xfb;
static GXRModeObj *rmode;


void Initialise() {
  
	VIDEO_Init();
	WPAD_Init();
 
	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
 
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}


int main() {
 
	Initialise();
 
	printf("Press any button...\n");
	
	while(1) {

		WPAD_ScanPads();
		
		u16 buttonsDown = WPAD_ButtonsDown(0);
		
		if( buttonsDown & WPAD_BUTTON_A ) {
			printf("Button A pressed.\n");
		}	
        
        if( buttonsDown & WPAD_BUTTON_B ) {
			printf("Button B pressed.\n");
		}	

        if( buttonsDown & WPAD_BUTTON_1 ) {
			printf("Button 1 pressed.\n");
		}	
        
        if( buttonsDown & WPAD_BUTTON_2 ) {
			printf("Button 2 pressed.\n");
		}	
        
		if( buttonsDown & WPAD_BUTTON_MINUS ) {
			printf("Button - pressed.\n");
		}	
        
        if( buttonsDown & WPAD_BUTTON_PLUS ) {
			printf("Button + pressed.\n");
		}	

        if( buttonsDown & NUNCHUK_BUTTON_Z ) {
			printf("Button Z pressed.\n");
		}	
        
        if( buttonsDown & NUNCHUK_BUTTON_C ) {
			printf("Button C pressed.\n");
		}	

        if( buttonsDown & WPAD_BUTTON_UP ) {
			printf("Upp arrow pressed.\n");
		}	
        
        if( buttonsDown & WPAD_BUTTON_DOWN) {
			printf("Down arrow pressed.\n");
		}	

        if( buttonsDown & WPAD_BUTTON_LEFT ) {
			printf("Left arrow pressed.\n");
		}	
        
        if( buttonsDown & WPAD_BUTTON_RIGHT ) {
			printf("Right arrow pressed.\n");
		}	
	}
 
	return 0;
}
