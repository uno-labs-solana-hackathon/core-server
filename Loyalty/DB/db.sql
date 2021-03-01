DROP SCHEMA sol CASCADE;
CREATE SCHEMA sol;

------------------------------------- sol.clients ---------------------------------------------
CREATE TABLE sol.clients
(
  id          text   NOT NULL PRIMARY KEY GENERATED ALWAYS AS (data->>'id') STORED,
  data        jsonb  NOT NULL,

  _version    bigint NOT NULL DEFAULT 0
)
WITH (
  OIDS=FALSE
);

------------------------------------- sol.buy_txs ---------------------------------------------
CREATE TABLE sol.buy_txs
(
  id          uuid   NOT NULL PRIMARY KEY GENERATED ALWAYS AS ((data->>'id')::uuid) STORED,
  data        jsonb  NOT NULL,

  _version    bigint NOT NULL DEFAULT 0
)
WITH (
  OIDS=FALSE
);

------------------------------------- sol.chain_txs ---------------------------------------------
CREATE TABLE sol.chain_txs
(
  id          uuid   NOT NULL PRIMARY KEY GENERATED ALWAYS AS ((data->>'id')::uuid) STORED,
  state       bigint NOT NULL DEFAULT 0,
  data        jsonb  NOT NULL,

  _version    bigint NOT NULL DEFAULT 0
)
WITH (
  OIDS=FALSE
);
