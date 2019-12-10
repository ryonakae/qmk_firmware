/* Copyright 2019 Ryo Nakae
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define ____ KC_NO

#define LAYOUT( \
    L000, L001, L002, L003, L004, L005,       R000, R001, R002, R003, R004, R005, R006, R007, \
    L100, L101, L102, L103, L104, L105,       R100, R101, R102, R103, R104, R105, R106, R107, \
    L200,       L201, L202, L203, L204, L205,       R200, R201, R202, R203, R204, R205,       \
    L300,       L301, L302, L303, L304, L305,       R300, R301, R302, R303, R304,       R305, \
    L400, L401, L402,                         L404,       R400, R401, R402, R403, R404, R405  \
) \
{ \
    { L000, L001, L002, L003, L004, L005, ____, ____ }, \
    { L100, L101, L102, L103, L104, L105, ____, ____ }, \
    { L200, L201, L202, L203, L204, L205, ____, ____ }, \
    { L300, L301, L302, L303, L304, L305, ____, ____ }, \
    { L400, L401, L402, ____, L404, ____, ____, ____ }, \
    { R000, R001, R002, R003, R004, R005, R006, R007 }, \
    { R100, R101, R102, R103, R104, R105, R106, R107 }, \
    { R200, R201, R202, R203, R204, R205, ____, ____ }, \
    { R300, R301, R302, R303, R304, R305, ____, ____ }, \
    { R400, R401, R402, R403, R404, R405, ____, ____ }  \
}

#define LAYOUT_kc( \
    L000, L001, L002, L003, L004, L005,       R000, R001, R002, R003, R004, R005, R006, R007, \
    L100, L101, L102, L103, L104, L105,       R100, R101, R102, R103, R104, R105, R106, R107, \
    L200,       L201, L202, L203, L204, L205,       R200, R201, R202, R203, R204, R205,       \
    L300,       L301, L302, L303, L304, L305,       R300, R301, R302, R303, R304,       R305, \
    L400, L401, L402,                         L404,       R400, R401, R402, R403, R404, R405  \
) \
LAYOUT( \
    KC_##L000, KC_##L001, KC_##L002, KC_##L003, KC_##L004, KC_##L005,            KC_##R000, KC_##R001, KC_##R002, KC_##R003, KC_##R004, KC_##R005, KC_##R006, KC_##R007, \
    KC_##L100, KC_##L101, KC_##L102, KC_##L103, KC_##L104, KC_##L105,            KC_##R100, KC_##R101, KC_##R102, KC_##R103, KC_##R104, KC_##R105, KC_##R106, KC_##R107, \
    KC_##L200,            KC_##L201, KC_##L202, KC_##L203, KC_##L204, KC_##L205,            KC_##R200, KC_##R201, KC_##R202, KC_##R203, KC_##R204, KC_##R205,            \
    KC_##L300,            KC_##L301, KC_##L302, KC_##L303, KC_##L304, KC_##L305,            KC_##R300, KC_##R301, KC_##R302, KC_##R303, KC_##R304,            KC_##R305, \
    KC_##L400, KC_##L401, KC_##L402,                                             KC_##L404,            KC_##R400, KC_##R401, KC_##R402, KC_##R403, KC_##R404, KC_##R405  \
)
