/* emu2149.h */
#ifndef _EMU2149_H_
#define _EMU2149_H_

#include <stdint.h>


#if __EMSCRIPTEN__
#include <emscripten.h>
#define VR_EMU_2149_DLLEXPORT EMSCRIPTEN_KEEPALIVE
#elif VR_EMU_2149_COMPILING_DLL
#define VR_EMU_2149_DLLEXPORT __declspec(dllexport)
#elif defined WIN32 && !defined VR_EMU_2149_STATIC
#define VR_EMU_2149_DLLEXPORT __declspec(dllimport)
#else
#ifdef __cplusplus
#define VR_EMU_2149_DLLEXPORT extern "C"
#else
#define VR_EMU_2149_DLLEXPORT extern
#endif
#endif

#define EMU2149_VOL_DEFAULT 1
#define EMU2149_VOL_YM2149 0
#define EMU2149_VOL_AY_3_8910 1

#define PSG_MASK_CH(x) (1<<(x))

  typedef struct __PSG
  {

    /* Volume Table */
    uint32_t *voltbl;

    uint8_t reg[0x20];
    int32_t out;

    uint32_t clk, rate, base_incr, quality;

    uint32_t count[3];
    uint32_t volume[3];
    uint32_t freq[3];
    uint32_t edge[3];
    uint32_t tmask[3];
    uint32_t nmask[3];
    uint32_t mask;

    uint32_t base_count;

    uint32_t env_volume;
    uint32_t env_ptr;
    uint32_t env_face;

    uint32_t env_continue;
    uint32_t env_attack;
    uint32_t env_alternate;
    uint32_t env_hold;
    uint32_t env_pause;
    uint32_t env_reset;

    uint32_t env_freq;
    uint32_t env_count;

    uint32_t noise_seed;
    uint32_t noise_count;
    uint32_t noise_freq;

    /* rate converter */
    uint32_t realstep;
    uint32_t psgtime;
    uint32_t psgstep;

    /* I/O Ctrl */
    uint32_t adr;

    /* output of channels */
    int16_t ch_out[3];

  } PSG;

  VR_EMU_2149_DLLEXPORT void PSG_set_quality (PSG * psg, uint32_t q);
  VR_EMU_2149_DLLEXPORT   void PSG_set_rate (PSG * psg, uint32_t r);
  VR_EMU_2149_DLLEXPORT PSG *PSG_new (uint32_t clk, uint32_t rate);
  VR_EMU_2149_DLLEXPORT void PSG_reset (PSG *);
  VR_EMU_2149_DLLEXPORT void PSG_delete (PSG *);
  VR_EMU_2149_DLLEXPORT void PSG_writeReg (PSG *, uint32_t reg, uint32_t val);
  VR_EMU_2149_DLLEXPORT void PSG_writeIO (PSG * psg, uint32_t adr, uint32_t val);
  VR_EMU_2149_DLLEXPORT uint8_t PSG_readReg (PSG * psg, uint32_t reg);
  VR_EMU_2149_DLLEXPORT uint8_t PSG_readIO (PSG * psg);
  VR_EMU_2149_DLLEXPORT int16_t PSG_calc (PSG *);
  VR_EMU_2149_DLLEXPORT void PSG_setVolumeMode (PSG * psg, int type);
  VR_EMU_2149_DLLEXPORT uint32_t PSG_setMask (PSG *, uint32_t mask);
  VR_EMU_2149_DLLEXPORT uint32_t PSG_toggleMask (PSG *, uint32_t mask);


#endif
