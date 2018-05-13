/*
 * Copyright 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mgos.h"
#include "mgos_imu_internal.h"

struct mgos_imu_acc *mgos_imu_acc_create(void) {
  struct mgos_imu_acc *acc;
  acc = calloc(1, sizeof(struct mgos_imu_acc));
  if (!acc) return NULL;
  memset(acc, 0, sizeof(struct mgos_imu_acc));

  acc->type=ACC_NONE;
  return acc;
}

bool mgos_imu_acc_destroy(struct mgos_imu_acc **acc) {
  if (!*acc) return false;
  if ((*acc)->destroy) (*acc)->destroy(*acc);
  if ((*acc)->user_data) free((*acc)->user_data);
  free(*acc);
  *acc=NULL;
  return true;
}
