FROM nginx:latest


HEALTHCHECK --interval=5m --timeout=3s \
  CMD curl -f http://localhost/ || exit 1

WORKDIR /home

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    gcc \
    libfcgi-dev \
    spawn-fcgi && \
    rm -rf /var/lib/apt/lists


COPY fcgi.c .
COPY run.sh .
COPY nginx.conf /etc/nginx/nginx.conf


RUN chown -R nginx:nginx /etc/nginx/ \
    && chown -R nginx:nginx /home/ \
    && chown -R nginx:nginx /var/log/nginx/ \
    && chown -R nginx:nginx /run/ \
    && chown -R nginx:nginx /var/cache/nginx \
    && touch /run/nginx.pid \
    && chown -R nginx:nginx /usr/src /run/nginx.pid 

USER nginx

ENTRYPOINT ["sh", "./run.sh"]
