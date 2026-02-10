<p align="center"></p>

## Table of Contents
- [Souls Like Combat Mechanics](#souls-like-combat-project)
  - [Project Overview](#souls-project-overview)
  - [Gameplay](#souls-gameplay)
  - [Project Details](#souls-project-details)
  - [Core Systems](#souls-core-systems)
  - [Combat Features](#souls-combat-features)
  - [Bow and Arrow](#souls-bow-and-arrow)
  - [Modular Projectile System](#souls-modular-projectile-system)
  - [Gameplay Abilities (GAS)](#souls-gameplay-abilities-gas)
  - [UI Feedback](#souls-ui-feedback)
  - [Changelog](#souls-changelog)


## Souls Project Details

| Platform | Engine | Tech | Team Size | Roles |
| --- | --- | --- | --- | --- |
| PC | Unreal Engine 5 | C++, Blueprints, GAS | Duo | Gameplay Programmer (Combat/Systems) |

---

## Souls Collaboration
Duo project built with a VFX artist.  
I handled GAS architecture, combat systems, AI combat hooks, and UI logic. The VFX artist delivered Niagara effects for attacks, abilities, hits, and elemental feedback to improve readability and impact.

---

## Souls Core Systems
- GAS based abilities with stamina costs, cooldowns, gameplay effects, and tags.
- Modular damage pipeline (hit reactions, stagger, death handling).
- Movement support for combat and traversal (vaulting, mantling, grounded locomotion).

---

## Souls Combat Features
- Multiple melee weapons with reusable combat framework.
- Light attacks and heavy combo chains with combo UI feedback.
- Charged attacks with scaling.
- Block/guard with stamina drain and guard break.
- Dodge/roll with stamina cost and i-frame window.
- Enemy AI combat loop (attack selection, reactions, pressure).

---

## Souls Bow and Arrow
- Draw, aim, release loop integrated with GAS.
- Target practice setup for tuning aim and timing.
- Data driven arrow types (fire, freeze, poison ready for expansion).

---

## Souls Modular Projectile System
- GAS driven projectile abilities (spawn, travel, impact, apply effects).
- Optional lock style auto targeting.
- Multiple projectile types supported via reusable projectile core.

---

## Souls Gameplay Abilities (GAS)
- Health and stamina attribute sets.
- Dash ability (GAS, cost, cooldown, prediction safe flow).
- Damage, hit reaction, stagger, and status effects as Gameplay Effects.
- Extensible ability framework for future skills.

---

## Souls UI Feedback
- Health and stamina bars bound to attributes.
- Cooldown UI hooks for abilities.
- Hit feedback indicators.
- Combo counter / combat state UI hooks.

---

## Souls Changelog

#### `01-12-2025:`
- Repo and project setup (UE5, modules, folder structure).
- Planned GAS ability structure and combat scope (melee, bow, projectiles, UI, AI).
- VFX collaboration pipeline setup (Niagara naming, event hooks, asset handoff).

#### `04-12-2025:`
- GAS foundation: ASC setup, base ability class, tags, input handling plan.
- Character integration for multiplayer safe ownership flow.

#### `08-12-2025:`
- Health/Stamina attribute sets + regen, costs, cooldown effects.
- Damage pipeline v1: apply damage effects + hooks for hit reaction.

#### `11-12-2025:`
- UI v1: health/stamina bars and cooldown placeholders wired to GAS.
- VFX pass 1: basic hit feedback and ability cues (VFX artist).

#### `15-12-2025:`
- Dash ability implemented with GAS (cost/cooldown, cancel rules).
- VFX pass 2: dash trail and start/end burst (VFX artist).

#### `18-12-2025:`
- Melee light attack ability v1 (montage driven, hit windows, damage apply).
- Hit reaction trigger support for targets.

#### `22-12-2025:`
- Heavy + charged attacks v1 (hold/release, stamina scaling).
- VFX pass 3: weapon swing trails + impact bursts (VFX artist).

#### `27-12-2025:`
- Combo chain system v1 (buffered inputs, combo UI counter).
- Bug fixes for montage flow and combo edge cases.

#### `02-01-2026:`
- Block/guard ability (stamina drain, guard break rules, directional checks).
- VFX pass 4: block sparks + guard break burst (VFX artist).

#### `06-01-2026:`
- Dodge/roll ability (stamina cost, i-frames, recovery timing).
- VFX pass 5: dodge trail and dust kick (VFX artist).

#### `10-01-2026:`
- Projectile framework via GAS (spawn, travel, impact, gameplay effects).
- Target practice test map for tuning projectiles and hit feedback.

#### `14-01-2026:`
- Bow and arrow v1 (draw/aim/release, stamina usage, projectile integration).
- VFX pass 6: arrow trails + impact bursts (VFX artist).

#### `18-01-2026:`
- Special arrows support (fire/freeze effects, data driven extension points).
- VFX pass 7: elemental trails and elemental impacts (VFX artist).

#### `22-01-2026:`
- Enemy AI combat hooks: ability granting, attack selection, reaction rules.
- Polished hit reaction/death flow for AI.

#### `26-01-2026:`
- Multiplayer and replication pass on abilities and projectiles.
- Fixed common prediction/desync issues (montages, projectiles, costs).

#### `30-01-2026:`
- Polish: combat readability, UI states (stamina low, cooldown ready).
- Documentation cleanup: tags, effects naming, key classes.

