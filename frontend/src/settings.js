
const host = process.env.API_HOST ? process.env.API_HOST : "localhost";
const port = process.env.API_PORT ? process.env.API_PORT : "8080";
export const apiUrl = `http://${host}:${port}/api/v1`; // "http://192.168.0.10:8080/api/v1";
export const apiHeader = {
  Accept: "application/json",
  "Content-Type": "application/json",
};

export const refreshTime = 30; //frequency of refreshing data in seconds
export const readingsInterval = 15; //interval of reading in which readings were taken in minutes

export const warnLevel = 800;
export const dangerLevel = 1000;

export const accessTimeForAdmin = 1 / 12; // Integer number means numbers of days. For example 1 / 12 means 1 hour
