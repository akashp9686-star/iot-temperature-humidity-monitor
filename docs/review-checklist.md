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
- [ ] Confirm latest GitHub Actions run is successful

## Physical verification (not part of the repository-only preparation)
- [ ] Sensor readings verified on a physical NodeMCU
- [ ] Wi-Fi and ThingSpeak publishing verified on the owner's configured account
- [ ] Actual pull-up resistor arrangement confirmed
- [ ] Genuine hardware evidence added, if requested by evaluator

Do not mark any unchecked physical verification item complete without performing it.
