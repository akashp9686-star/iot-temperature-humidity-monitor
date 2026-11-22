# Testing and Verification Record

## Status at repository preparation

| Item | Status |
|---|---|
| Repository documentation created | Completed |
| Firmware source included | Included; not hardware-verified |
| PlatformIO configuration included | Included; build not run in this environment |
| CSV example format test | Can be run locally |
| Physical DHT sensor test | Not verified |
| ESP8266 upload test | Not verified |
| Wi-Fi connection test | Not verified |
| ThingSpeak upload / dashboard test | Not verified |
| Project demonstration photos | Not supplied |

## Local software check

Run:

```bash
python -m unittest discover -s tests -v
```

This validates the sample CSV structure and broad numeric bounds only. It does not simulate the DHT protocol, compile the firmware, or prove that hardware works.

## Hardware verification checklist

When the physical device is available, record the date, board model, sensor model, data GPIO, firmware version and observed results. Capture genuine photographs or serial logs if required by the submission reviewer.

- [ ] Confirm sensor model and wiring
- [ ] Build firmware with PlatformIO
- [ ] Upload to the NodeMCU
- [ ] Confirm temperature and humidity appear on Serial Monitor
- [ ] If enabled, confirm ThingSpeak receives both fields
- [ ] Save genuine evidence and update this document

Do not mark unchecked items complete without performing the corresponding test.
