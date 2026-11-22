# Evaluator Guide — Project 01

## Project
IoT Temperature & Humidity Monitoring System — ESP8266 NodeMCU, DHT11 and ThingSpeak.

## What to review
- Firmware: `src/main.cpp`
- Build configuration: `platformio.ini`
- Safe configuration template: `include/config.example.h`
- System design and wiring: `docs/architecture.md`, `docs/wiring.md`
- Verification scope: `docs/testing.md`, `docs/review-checklist.md`
- Illustrative sample readings and automated checks: `examples/`, `tests/`

## Reproducible software checks
1. Install PlatformIO.
2. Copy `include/config.example.h` to `include/config.h`.
3. Keep the placeholder credentials for compilation, or add private local credentials for a real deployment.
4. Run `pio run`.
5. Run `python -m unittest discover -s tests -v`.

The GitHub Actions workflow provides hosted build/test evidence. Review the linked workflow badge and Actions history for the actual run result.

## Scope and evidence
The project owner reports the DHT11 data pin as NodeMCU D2/GPIO4 and reports prior ThingSpeak publishing. These are owner-reported details, not independently reproduced by this repository review. The automated workflow does not test the physical sensor, Wi-Fi, or live ThingSpeak channel. No independent physical test evidence or live dashboard capture is currently included.

The optional temperature-threshold alert is not implemented and must not be evaluated as a completed feature.

## Evaluator request
Please assess the repository's source code, design documentation, research references, software build and automated tests. Please advise whether this repository-based evidence is sufficient for your evaluation process and identify any additional physical demonstration or evidence required.
