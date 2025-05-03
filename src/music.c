#include <gb/gb.h>
#include "hUGEDriver.h"
#include "music.h"

// Declaras la canci�n exportada
extern const hUGESong_t title_theme;

void music_init(void) {
    NR52_REG = 0x80; // Habilitar sonido
    NR50_REG = 0xFF; // Volumen m�ximo
    NR51_REG = 0xFF; // Habilitar todos los canales

    __critical {
        hUGE_init(&title_theme);       // Iniciar canci�n
        add_VBL(hUGE_dosound);         // Reproducir sonido cada frame
    }
}