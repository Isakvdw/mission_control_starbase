# mission_control_starbase



---
## mission_control


out/  
> needs to be created, holds all .o files

Builder/  
- Builder
- ConcreteBuilder  

Payload/  
- Payload
- Dragon
- DragonCrew
- Starlink
 - SateliteLauncher
 - Satelite
 - Factory  
 - SateliteFactory  

Propulsion/  
- Propulsion
- Engine
- Booster
- Falcon
- FalconHeavy
- SecondStage
 - FuelObserver
 - Observer  

State/  
- State
- BuildS
- FuelS
- LaunchS
- ActiveLaunchS

Storage/  
- RocketMemento
- Caretaker
- Aggregate
- RocketAggregate
- Iterator
- RocketIterator
