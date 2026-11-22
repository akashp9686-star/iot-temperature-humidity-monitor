# Repository Review Checklist

## Repository and source
- [x] Public GitHub repository
- [x] README with project purpose, setup and limitations
- [x] PlatformIO project configuration
- [x] Firmware source code
- [x] Example configuration without private credentials
- [x] Git ignore rules for local secrets and build outputs
- [x] Wiring and architecture documentation

## Research and software verification
- [x] Technical research and references documented
- [x] Automated PlatformIO build workflow configured
- [x] Automated sample CSV validation tests included
- [x] Confirm latest GitHub Actions run is successful ([run 44999101950](https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions/runs/44999101950))

## Physical verification (not part of the repository-only preparation)
- [ ] Sensor readings verified on a physical NodeMCU
- [ ] Wi-Fi and ThingSpeak publishing verified on the owner's configured account
- [ ] Actual pull-up resistor arrangement confirmed
- [ ] Genuine hardware evidence added, if requested by evaluator

Do not mark any unchecked physical verification item complete without performing it.
