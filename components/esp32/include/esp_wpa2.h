// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ESP_WPA2_H
#define ESP_WPA2_H

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  Enable wpa2 enterprise authentication.
  *
  * @attention wpa2 enterprise authentication can only be used when ESP32 station is enabled.
  *            wpa2 enterprise authentication can only support TLS, PEAP-MSCHAPv2 and TTLS-MSCHAPv2 method.
  *
  * @param  null
  *
  * @return ESP_ERR_WIFI_OK: succeed.
  *         ESP_ERR_WIFI_NO_MEM: fail(internal memory malloc fail)
  */
esp_err_t esp_wifi_sta_wpa2_enterprise_enable(void);

/**
  * @brief  Disable wpa2 enterprise authentication.
  *
  * @attention wpa2 enterprise authentication can only be used when ESP32 station is enabled.
  *            wpa2 enterprise authentication can only support TLS, PEAP-MSCHAPv2 and TTLS-MSCHAPv2 method.
  *
  * @param  null
  *
  * @return ESP_ERR_WIFI_OK: succeed.
  */
esp_err_t esp_wifi_sta_wpa2_enterprise_disable(void);

/**
  * @brief  Set username for PEAP/TTLS method.
  *
  * @param  username: point to address where stores the username;
  *         len: length of username, limited to 1~127
  *
  * @return ESP_ERR_WIFI_OK: succeed
  *         ESP_ERR_WIFI_ARG: fail(len <= 0 or len >= 128)
  *         ESP_ERR_WIFI_NO_MEM: fail(internal memory malloc fail)
  */
esp_err_t esp_wifi_sta_set_enterprise_username(unsigned char *username, int len);

/**
  * @brief  Clear username for PEAP/TTLS method.
  *
  * @param  null
  *
  * @return  null
  */
void esp_wifi_sta_clear_enterprise_username(void);

/**
  * @brief  Set password for PEAP/TTLS method..
  *
  * @param  password: point to address where stores the password;
  *         len: length of password
  *
  * @return ESP_ERR_WIFI_OK: succeed
  *         ESP_ERR_WIFI_ARG: fail(len <= 0)
  *         ESP_ERR_WIFI_NO_MEM: fail(internal memory malloc fail)
  */
esp_err_t esp_wifi_sta_set_enterprise_password(unsigned char *password, int len);

/**
  * @brief  Clear password for PEAP/TTLS method..
  *
  * @param  null
  *
  * @return  null
  */
void esp_wifi_sta_clear_enterprise_password(void);

/**
  * @brief  Set new password for PEAP/TTLS method..
  *
  * @param  password: point to address where stores the password;
  *         len: length of password
  *
  * @return ESP_ERR_WIFI_OK: succeed
  *         ESP_ERR_WIFI_ARG: fail(len <= 0)
  *         ESP_ERR_WIFI_NO_MEM: fail(internal memory malloc fail)
  */

esp_err_t esp_wifi_sta_set_enterprise_new_password(unsigned char *password, int len);

/**
  * @brief  Clear new password for PEAP/TTLS method..
  *
  * @param  null
  *
  * @return  null
  */
void esp_wifi_sta_clear_enterprise_new_password(void);

/**
  * @brief  Set CA certificate for PEAP/TTLS method.
  *
  * @param  ca_cert: point to address where stores the CA certificate;
  *         len: length of ca_cert
  *
  * @return ESP_ERR_WIFI_OK: succeed
  */
esp_err_t esp_wifi_sta_set_enterprise_ca_cert(unsigned char *ca_cert, int len);

/**
  * @brief  Clear CA certificate for PEAP/TTLS method.
  *
  * @param  null
  *
  * @return  null
  */
void esp_wifi_sta_clear_enterprise_ca_cert(void);

/**
  * @brief  Set client certificate and key.
  *
  * @param  client_cert: point to address where stores the client certificate;
  *         client_cert_len: length of client certificate;
  *         private_key: point to address where stores the private key;
  *         private_key_len: length of private key;
  *         private_key_password: point to address where stores the private key password;
  *         private_key_password_len: length of private key password;
  *
  * @return ESP_ERR_WIFI_OK: succeed
  */
esp_err_t esp_wifi_sta_set_enterprise_cert_key(unsigned char *client_cert, int client_cert_len, unsigned char *private_key, int private_key_len, unsigned char *private_key_passwd, int private_key_passwd_len);

/**
  * @brief  Clear client certificate and key.
  *
  * @param  null
  *
  * @return  null
  */
void esp_wifi_sta_clear_enterprise_cert_key(void);

/**
  * @brief  Set wpa2 enterprise certs time check(disable or not).
  *
  * @param  true: disable wpa2 enterprise certs time check
  *         false: enable wpa2 enterprise certs time check
  *
  * @return  ESP_ERR_WIFI_OK: succeed
  */
esp_err_t esp_wifi_sta_set_enterprise_disable_time_check(bool disable);

/**
  * @brief  Get wpa2 enterprise certs time check(disable or not).
  *
  * @param  disable: store disable value
  *
  * @return  ESP_ERR_WIFI_OK: succeed
  */
esp_err_t esp_wifi_sta_get_enterprise_disable_time_check(bool *disable);

#ifdef __cplusplus
}
#endif
#endif
